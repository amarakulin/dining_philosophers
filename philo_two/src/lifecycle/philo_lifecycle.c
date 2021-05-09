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

#include "philo_two.h"

int	action_philo(t_philosopher *philo, t_parameters *param, \
	t_semaphore *semaphore, void *arg)
{
	take_fork(philo, semaphore);
	print_philo_message(philo, semaphore, TAKEN_FORK);
	print_philo_message(philo, semaphore, EATING);
	my_usleep(param->time_to_eat);
	if (!put_fork(philo, semaphore, param->times_must_to_eat))
	{
		free(arg);
		return (0);
	}
	print_philo_message(philo, semaphore, SLEEPING);
	my_usleep(param->time_to_sleep);
	print_philo_message(philo, semaphore, THINKING);
	return (1);
}

void	*philo_lifecycle(void *arg)
{
	t_lifecycle		*lifecycle_struct;
	t_self			*self;
	t_philosopher	*philo;
	int				index_philo;

	lifecycle_struct = arg;
	self = lifecycle_struct->self;
	index_philo = lifecycle_struct->index_philo;
	philo = &self->arr_philo[index_philo];
	if (philo->index_philo % 2 == 0)
		my_usleep(10);
	sem_wait(self->semaphore->sem_last_meal);
	philo->last_meal = get_current_time();
	sem_post(self->semaphore->sem_last_meal);
	while (1)
	{
		if (!action_philo(philo, self->param, self->semaphore, arg))
			return (NULL);
	}
}

t_lifecycle	*constract_lifecycle(t_self *self, int i)
{
	t_lifecycle	*lifecycle;

	lifecycle = ft_calloc(1, sizeof(t_lifecycle));
	lifecycle->self = self;
	lifecycle->index_philo = i;
	return (lifecycle);
}

void	create_threads(t_self *self)
{
	int				i;
	pthread_t		thread_death;
	t_philosopher	*arr_philo;

	i = 0;
	arr_philo = self->arr_philo;
	pthread_create(&thread_death, NULL, is_philosopher_death, (void *)self);
	while (i != self->param->nbr_philosophers)
	{
		pthread_create(&arr_philo[i].thread_id, NULL, philo_lifecycle, \
		(void *)constract_lifecycle(self, i));
		i++;
	}
	pthread_join(thread_death, NULL);
	i = 0;
	while (i != self->param->nbr_philosophers)
	{
		pthread_detach(&arr_philo->thread_id[i]);
		i++;
	}
}
