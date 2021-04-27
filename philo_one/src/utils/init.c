/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 22:06:58 by tilda             #+#    #+#             */
/*   Updated: 2021/04/23 22:07:00 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philosopher	*init_philosophers(t_parameters *param)
{
	int 			i;
	t_philosopher	*arr_philosophers;

	i = 0;
	arr_philosophers = ft_calloc(param->nbr_philosophers, sizeof(t_philosopher));
	while(i != param->nbr_philosophers)
	{
		arr_philosophers[i].index_philo = i;
		arr_philosophers[i].times_ate = 0;
		arr_philosophers[i].last_meal = 0;
		arr_philosophers[i].param = param;
		arr_philosophers[i].is_right_fork = &arr_philosophers->param->arr_fork[i];
		arr_philosophers[i].is_left_fork = &arr_philosophers->param->arr_fork[left(
				i, param->nbr_philosophers)];
		printf("philo - %d | right - %d | left - %d\n", i, i, left(i, param->nbr_philosophers));
		arr_philosophers[i].mutex_last_meal = &arr_philosophers->param->arr_mutex_last_meal[i];
		arr_philosophers[i].mutex_times_ate = &arr_philosophers->param->arr_times_to_eat[i];
		i++;
	}
	return (arr_philosophers);
}

t_parameters	*get_parameters(int argc, char *argv[])
{
	int		i;
	char	**copy_argv;
	t_parameters *param;

	i = 0;
	copy_argv = argv;
	param = ft_calloc(sizeof(t_parameters), 1);
	param->nbr_philosophers = (int)ft_atoi(copy_argv[1]);
	param->time_to_die = ft_atoi(copy_argv[2]);
	param->time_to_eat = ft_atoi(copy_argv[3]);
	param->time_to_sleep = ft_atoi(copy_argv[4]);
	if (argc == 6)
		param->times_must_to_eat = (int)ft_atoi(copy_argv[5]); //at least they could eat 0 times
	else
		param->times_must_to_eat = -1;
	param->wait_all_philo = ft_calloc(sizeof(char), param->nbr_philosophers + 1);
	param->arr_fork = ft_calloc(sizeof(pthread_mutex_t), param->nbr_philosophers);
	param->arr_times_to_eat = ft_calloc(sizeof(pthread_mutex_t), param->nbr_philosophers);
	param->arr_mutex_last_meal = ft_calloc(sizeof(pthread_mutex_t), param->nbr_philosophers);
	while (i != param->nbr_philosophers)
	{
		pthread_mutex_init(&param->arr_fork[i], NULL);
		pthread_mutex_init(&param->arr_mutex_last_meal[i], NULL);
		pthread_mutex_init(&param->arr_times_to_eat[i], NULL);
		i++;
	}
	pthread_mutex_init(&param->print_mutex, NULL);
	printf("TIMES MUST EAT - %d\n", param->times_must_to_eat);
	return (param);
}