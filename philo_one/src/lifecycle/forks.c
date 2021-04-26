/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:34:49 by tilda             #+#    #+#             */
/*   Updated: 2021/04/25 21:35:03 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			left(int position_philo, int total_philosophers)
{
	return ((position_philo + 1) % total_philosophers);
}

int			get_fork(t_philosopher* philo)
{
	if (philo->number_of_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->is_right_fork);
		printf("Philo take left - %d\n", philo->number_of_philo);
		pthread_mutex_lock(philo->is_left_fork);
		printf("Philo take left - %d\n", philo->number_of_philo);
	}
	else
	{
		pthread_mutex_lock(philo->is_left_fork);
		printf("Philo take left - %d\n", philo->number_of_philo);
		pthread_mutex_lock(philo->is_right_fork);
		printf("Philo take left - %d\n", philo->number_of_philo);
	}
	return (0);
}

void		put_fork(t_philosopher* philo)
{
	pthread_mutex_unlock(philo->is_right_fork);
	printf("Philo put left - %d\n", philo->number_of_philo);
	pthread_mutex_unlock(philo->is_left_fork);
	printf("Philo put left - %d\n", philo->number_of_philo);
}