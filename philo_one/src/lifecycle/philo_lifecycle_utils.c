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

	philo->state = SIT_TO_TABLE;
	index_philo = philo->numberOfPhilo;
	while(1)
	{
		if (philo->state == SIT_TO_TABLE)
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
