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
	return ((position_philo - 1 + total_philosophers) % total_philosophers);
}

int			get_fork_pair_philo(t_philosopher* philo, int index_philo)
{
	if (philo->is_right_fork && philo->param->fork_arr[index_philo])
	{
		if (!philo->is_left_fork && !philo->param->fork_arr[left(index_philo, philo->number_of_philo)])
		{
			philo->is_left_fork = 1;
			philo->param->fork_arr[left(index_philo, philo->number_of_philo)] = philo->is_left_fork;
			return (1);
		}
	}
	else
	{
		if (!philo->param->fork_arr[index_philo])
		{
			philo->is_right_fork = 1;
			philo->param->fork_arr[index_philo] = philo->is_right_fork;
		}
	}
	return (0);
}

int			get_fork_impair_philo(t_philosopher* philo, int index_philo)
{
	if (philo->is_left_fork && philo->param->fork_arr[left(index_philo, philo->number_of_philo)])
	{
		if (!philo->is_right_fork && !philo->param->fork_arr[index_philo])
		{
			philo->is_right_fork = 1;
			philo->param->fork_arr[index_philo] = philo->is_right_fork;
			return (1);
		}
	}
	else
	{
		if (!philo->param->fork_arr[left(index_philo, philo->number_of_philo)])
		{
			philo->is_left_fork = 1;
			philo->param->fork_arr[left(index_philo, philo->number_of_philo)] = philo->is_left_fork;
		}
	}
	return (0);
}

int			get_fork(t_philosopher* philo)
{
	int		index_philo;

	index_philo = philo->number_of_philo;
	while (1)
	{
		if (index_philo % 2 == 0)
		{
			if (get_fork_pair_philo(philo, index_philo))
				return (1);
		}
		else
		{
			if (get_fork_impair_philo(philo, index_philo))
				return (1);
		}
	}
	return (0);
}

void		put_fork(t_philosopher* philo)
{
	int		index_philo;

	index_philo = philo->number_of_philo;
	philo->is_right_fork = 0;
	philo->is_left_fork = 0;
	philo->param->fork_arr[index_philo] = philo->is_right_fork;
	philo->param->fork_arr[left(index_philo, philo->number_of_philo)] = philo->is_left_fork;
}