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


int				is_philosopher_death(t_philosopher *arr_philo, t_parameters param)
{
	int		i;

	i = 0;
	while (param.nbr_philosophers != i)
	{
		if (arr_philo[i].state == DIED)
			return (1);
	}
	return (0);
}

void			*philo_lifecycle(void *arg)
{
	t_philosopher	*philo;
	struct timeval	time;
	long int		curr_time;
	long int		start_time;

	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	philo = arg;
	while (1)
	{
		curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		gettimeofday(&time, NULL);
		printf("time_stand_ms - %ld\n", curr_time - start_time);
		printf("I am a philo - %d\n", philo->numberOfPhilo);
	}
	return (NULL);
}

void			create_philo_threads(t_data *data)
{
	int				i;
	int				j;
	t_parameters	*param;
	t_philosopher	*arr_philo;

	i = 0;
	param = data->param;
	arr_philo = data->arr_philo;
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