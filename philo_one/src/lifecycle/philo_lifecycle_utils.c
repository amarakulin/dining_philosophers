/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:31:05 by tilda             #+#    #+#             */
/*   Updated: 2021/04/24 22:31:06 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	wait_philo_sit_to_table(t_philosopher *philo)
{
	int		i;
	int		count;
	int		index_philo;

	philo->state = THOUGHT;
	index_philo = philo->number_of_philo;
	while(1)
	{
		if (philo->state == THOUGHT)
			philo->param->wait_all_philo[index_philo] = '1';
		count = 0;
		i = 0;
		while (philo->param->wait_all_philo[i])
		{
			if (philo->param->wait_all_philo[i] == '1')
				count++;
			i++;
		}
		if (count == philo->param->nbr_philosophers)
			break ;
	}
}

int		my_usleep(useconds_t usec)
{
	struct timeval	time;
	long int		curr_time;
	long int		start_time;

	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	while(curr_time - start_time < usec)
	{
		gettimeofday(&time, NULL);
		curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (usleep(10) == -1)
			return (-1);
	}
	return (0);
}