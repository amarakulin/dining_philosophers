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

void			*is_philosopher_death(void *arg)
{
	int		i;
	t_philosopher	*arr_philo;

	arr_philo = arg;
	i = 0;
	while (arr_philo->param->nbr_philosophers != i)
	{
		if (arr_philo[i].state == DIED)
		{
			break;
		}
	}
	return (NULL);
}

void			*philo_lifecycle(void *arg)
{
	t_philosopher	*philo;
	struct timeval	time;
	long int		curr_time;
	long int		start_time;

	//TODO wait all philo | use arr
	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	philo = arg;
	while (1)
	{
		curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		gettimeofday(&time, NULL);
		printf("time_stand_ms - %ld\n", curr_time - start_time);
		printf("I am a philo - %d\n", philo->numberOfPhilo);
		if (curr_time - philo->last_meal >= philo->param->time_to_die)
		{
			philo->state = DIED;
//			break;
		}
	}
	return (NULL);
}

void create_philo_threads(t_parameters *param, t_philosopher *arr_philo)
{
	int				i;
	int				j;
	pthread_t		thread_death;

	i = 0;
	pthread_create(&thread_death, NULL, is_philosopher_death, (void *)arr_philo);
	while (i != param->nbr_philosophers)
	{
		pthread_create(&arr_philo[i].thread_id, NULL, philo_lifecycle, (void *)&arr_philo[i]);
		i++;
	}
	j = 0;
	pthread_join(thread_death, NULL);
	while (j != param->nbr_philosophers)
	{
//		pthread_join(arr_philo[j].thread_id, NULL);
		j++;
	}
}