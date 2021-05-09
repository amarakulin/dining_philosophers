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

#include "philo_three.h"

const char	*g_philo_msg[5] = {"has taken a fork",
							  "is eating",
							  "is sleeping",
							  "is thinking",
							  "died"};

void	print_philo_message(t_philosopher *philo, t_semaphore *semaphore, \
		t_action_philo action)
{
	sem_wait(semaphore->print_sem);
	printf("%ld %d %s\n", get_current_time(), philo->index_philo + 1, \
	g_philo_msg[action]);
	sem_post(semaphore->print_sem);
}

void	print_times_ate(t_philosopher *arr_philo, t_parameters *param)
{
	int	i;

	i = 0;
	while (param->nbr_philosophers != i)
	{
		printf("Philo - %d ATE %d times \n", arr_philo[i].index_philo + 1, \
		arr_philo[i].times_ate);
		i++;
	}
}

int	wait_philo_sit_to_table(t_philosopher *philo, t_parameters *param)
{
	int	index_philo;

	index_philo = philo->index_philo;
	param->wait_all_philo[index_philo] = '1';
	while (strlen(param->wait_all_philo) != param->nbr_philosophers)
		;
	return (0);
}

int	my_usleep(useconds_t usec)
{
	long int	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < usec && usec < 100)
	{
		if (usleep(100) == -1)
			return (-1);
	}
	if (usec < 100)
		usleep(usec);
	return (0);
}
