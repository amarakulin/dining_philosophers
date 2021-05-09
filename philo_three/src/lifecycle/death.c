/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:13:05 by tilda             #+#    #+#             */
/*   Updated: 2021/04/28 19:13:06 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	is_philo_died(t_philosopher *philo, t_parameters *param,
				t_semaphore *semaphore)
{
	int			is_time_to_die;
	int			is_done_eat;
	long int	cur_time;
	long int	last_meal;

	cur_time = get_current_time();
	sem_wait(semaphore->sem_last_meal);
	last_meal = philo->last_meal;
	sem_post(semaphore->sem_last_meal);
	sem_wait(semaphore->sem_times_to_eat);
	is_done_eat = philo->times_ate == param->times_must_to_eat;
	sem_post(semaphore->sem_times_to_eat);
	is_time_to_die = cur_time - last_meal > param->time_to_die \
	&& last_meal != 0;
	if (is_time_to_die && !is_done_eat)
		return (philo->index_philo);
	return (-1);
}

void	*is_philosopher_death(void *arg)
{
	int				index_died_philo;
	t_death_thread	*death_thread;
	t_self			*self;
	t_philosopher	*philo;

	death_thread = arg;
	self = death_thread->self;
	philo = &self->arr_philo[death_thread->index_philo];
	while (1)
	{
		index_died_philo = is_philo_died(philo, self->param, self->semaphore);
		if (index_died_philo != -1)
		{
			print_philo_message(philo, self->semaphore, DIED);
			exit (0);
		}
	}
}
