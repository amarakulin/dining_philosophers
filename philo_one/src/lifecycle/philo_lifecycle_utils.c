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

int		wait_philo_sit_to_table(t_philosopher *philo)
{
	int		index_philo;

	index_philo = philo->index_philo;
	philo->param->wait_all_philo[index_philo] = '1';
	while(strlen(philo->param->wait_all_philo) != philo->param->nbr_philosophers);
	return 0;
}

int		my_usleep(useconds_t usec)
{
	long int		start_time;

	start_time = get_current_time();
	while(get_current_time() - start_time < usec)
	{
		if (usleep(10) == -1)
			return (-1);
	}
	return (0);
}