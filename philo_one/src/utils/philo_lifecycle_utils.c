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

const char	*g_philo_msg[5] = {"has taken a fork",
							  "is eating",
							  "is sleeping",
							  "is thinking",
							  "died"};

void	print_philo_message(t_philosopher *philo, t_parameters *param, t_mutex *mutex, \
		t_action_philo action)
{
	if (action == DIED)
	{
		pthread_mutex_lock(&mutex->print_mutex);
		printf("%ld %d %s\n", get_current_time() - param->start_time, philo->index_philo + 1, \
		g_philo_msg[action]);
	}
	else
	{
		pthread_mutex_lock(&mutex->print_mutex);
		printf("%ld %d %s\n", get_current_time() - param->start_time, philo->index_philo + 1, \
		g_philo_msg[action]);
		pthread_mutex_unlock(&mutex->print_mutex);
	}
}

int	my_usleep(useconds_t usec)
{
	long int	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < usec && usec > 100)
	{
		if (usleep(100) == -1)
			return (-1);
	}
	if (usec < 100)
		usleep(usec);
	return (0);
}
