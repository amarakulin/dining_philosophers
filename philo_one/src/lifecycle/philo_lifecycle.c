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
	struct timeval	time;
	long int		curr_time;

	arr_philo = arg;
	i = 0;
	while (arr_philo->param->nbr_philosophers != i)
	{
		gettimeofday(&time, NULL);
		curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (curr_time - arr_philo[i].last_meal >= arr_philo->param->time_to_die)
		{
			arr_philo[i].state = DIED;
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
		gettimeofday(&time, NULL);
		curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		printf("time_stand_ms - %ld\n", curr_time - start_time);
		printf("I am a philo - %d\n", philo->numberOfPhilo);
	}
	return (NULL);
}

void			create_threads(t_parameters *param, t_philosopher *arr_philo)
{
	int				i;
	pthread_t		thread_death;

	i = 0;
	//TODO Create thread to print out in the terminal info
	pthread_create(&thread_death, NULL, is_philosopher_death, (void *)arr_philo);
	while (i != param->nbr_philosophers)
	{
		pthread_create(&arr_philo[i].thread_id, NULL, philo_lifecycle, (void *)&arr_philo[i]);
		i++;
	}
	pthread_join(thread_death, NULL);
}