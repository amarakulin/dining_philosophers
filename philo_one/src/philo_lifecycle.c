/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:21:06 by tilda             #+#    #+#             */
/*   Updated: 2021/04/22 12:21:07 by tilda            ###   ########.fr       */
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
		arr_philosophers[i].state = START_SIMULATION;
		arr_philosophers[i].last_meal = 0;
		arr_philosophers[i].numberOfPhilo = i;
		i++;
	}
	return (arr_philosophers);
}

int				is_philosopher_death(t_philosopher *philo)
{
	if (philo->state == DIED)
		return (0);
	return (1);
}

void			*philo_lifecycle(void *arg)
{
	t_philosopher	*philo;
	struct timeval	curr_time;

	philo = arg;
	while (1)
	{
		gettimeofday(&curr_time, NULL);
		printf("time_stand_ms - %ld\n", curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
		printf("I am a philo - %d\n", philo->numberOfPhilo);
	}
	return (NULL);
}

void			create_philo_threads(t_philosopher *arr_philo, t_parameters *param)
{
	int				i;
	int				j;

	i = 0;
	while (i != param->nbr_philosophers)
	{
		pthread_create(&arr_philo[i].thread_id, NULL, philo_lifecycle, (void *)&arr_philo[i]);
		i++;
	}
	j = 0;
	while (j != param->nbr_philosophers)
	{
		pthread_join(arr_philo[j].thread_id, NULL);
		j++;
	}
}