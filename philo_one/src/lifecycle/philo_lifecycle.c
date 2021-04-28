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

void	*philo_lifecycle(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	while(wait_philo_sit_to_table(philo));
	if (philo->index_philo % 2 == 0)
		my_usleep(10);
	pthread_mutex_lock(philo->mutex_last_meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->mutex_last_meal);
	while (1)
	{
		take_fork(philo);
		print_philo_message(philo, TAKEN_FORK);
		print_philo_message(philo, EATING);
		my_usleep(philo->param->time_to_eat);
		if (!put_fork(philo))
			return (NULL);
		print_philo_message(philo, SLEEPING);
		my_usleep(philo->param->time_to_sleep);
		print_philo_message(philo, THINKING);
	}
}

void	create_threads(t_parameters *param, t_philosopher *arr_philo)
{
	int			i;
	pthread_t	thread_death;

	i = 0;
	pthread_create(&thread_death, NULL, is_philosopher_death, (void *)arr_philo);
	while (i != param->nbr_philosophers)
	{
		pthread_create(&arr_philo[i].thread_id, NULL, philo_lifecycle, (void *)&arr_philo[i]);
		i++;
	}
	pthread_join(thread_death, NULL);
}