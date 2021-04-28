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

const char *philo_msg[5] = {"has taken a fork",
							"is eating",
							"is sleeping",
							"is thinking",
							"died"};

void		print_philo_message(t_philosopher *philo, t_mutex *mutex,
						t_action_philo action)
{
	pthread_mutex_lock(&mutex->print_mutex);
	printf("%ld %d %s\n", get_current_time(), philo->index_philo + 1, philo_msg[action]);
	pthread_mutex_unlock(&mutex->print_mutex);
}

void		print_times_ate(t_philosopher *arr_philo, t_parameters *param)
{
	int		i;

	i = 0;
	while (param->nbr_philosophers != i)
	{
		printf("Philo - %d ATE %d times \n", arr_philo[i].index_philo + 1, arr_philo[i].times_ate);
		i++;
	}
}

int		wait_philo_sit_to_table(t_philosopher *philo, t_parameters *param)
{
	int		index_philo;

	index_philo = philo->index_philo;
	param->wait_all_philo[index_philo] = '1';
	while(strlen(param->wait_all_philo) != param->nbr_philosophers);
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