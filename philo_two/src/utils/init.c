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

#include "philo_two.h"

t_semaphore	*init_semaphore(t_parameters *param)
{
	t_semaphore	*semaphore;

	sem_unlink("sem_fork");
	sem_unlink("sem_times_to_eat");
	sem_unlink("sem_last_meal");
	sem_unlink("print_sem");
	semaphore = ft_calloc(1, sizeof(t_semaphore));
	semaphore->sem_fork = sem_open("sem_fork", O_CREAT, 0664, param->nbr_philosophers);
	semaphore->sem_times_to_eat = sem_open("sem_times_to_eat", O_CREAT, 0664, param->nbr_philosophers);
	semaphore->sem_last_meal = sem_open("sem_last_meal", O_CREAT, 0664, param->nbr_philosophers);
	semaphore->print_sem = sem_open("print_sem", O_CREAT, 0664, 1);
	return (semaphore);
}

t_philosopher	*init_philosophers(t_parameters *param, t_semaphore *mutex)
{
	int				i;
	t_philosopher	*arr_philosophers;

	i = 0;
	arr_philosophers = ft_calloc(param->nbr_philosophers, \
	sizeof(t_philosopher));
	while (i != param->nbr_philosophers)
	{
		arr_philosophers[i].index_philo = i;
		arr_philosophers[i].times_ate = 0;
		arr_philosophers[i].last_meal = 0;
		i++;
	}
	return (arr_philosophers);
}

t_parameters	*get_parameters(int argc, char *argv[])
{
	t_parameters	*param;

	param = ft_calloc(sizeof(t_parameters), 1);
	param->nbr_philosophers = (int)ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		param->times_must_to_eat = (int)ft_atoi(argv[5]);
	else
		param->times_must_to_eat = -1;
	param->wait_all_philo = ft_calloc(sizeof(char), \
	param->nbr_philosophers + 1);
	return (param);
}
