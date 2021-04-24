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
	struct timeval	time;
	long int		curr_time;

	i = 0;
	arr_philosophers = ft_calloc(param->nbr_philosophers, sizeof(t_philosopher));
	while(i != param->nbr_philosophers)
	{
		gettimeofday(&time, NULL);
		curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		arr_philosophers[i].state = START_SIMULATION;
		arr_philosophers[i].last_meal = 0;
		arr_philosophers[i].numberOfPhilo = i;
		arr_philosophers[i].last_meal = curr_time;
		arr_philosophers[i].param = param;
		i++;
	}
	return (arr_philosophers);
}


t_parameters	*get_parameters(int argc, char *argv[])
{
	char **copy_argv;
	t_parameters *parameters;

	parameters = ft_calloc(sizeof(t_parameters),1);
	copy_argv = argv;
	parameters->nbr_philosophers = ft_atoi(copy_argv[1]);
	parameters->time_to_die = ft_atoi(copy_argv[2]);
	parameters->time_to_eat = ft_atoi(copy_argv[3]);
	parameters->time_to_sleep = ft_atoi(copy_argv[4]);
	if (argc == 6)
		parameters->times_must_to_eat = ft_atoi(copy_argv[5]); //at least they could eat 0 times
	else
		parameters->times_must_to_eat = -1;
	return (parameters);
}