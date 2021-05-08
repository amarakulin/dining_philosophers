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

#include "philo_two.h"

int is_philo_died(t_philosopher *arr_philo, t_parameters *param,
				t_semaphore *semaphore)
{
	int			i;
	int			is_time_to_die;
	int			is_done_eat;
	long int	cur_time;
	long int	last_meal;

	i = 0;
	while (param->nbr_philosophers != i)
	{
		cur_time = get_current_time();
		sem_wait(semaphore->sem_last_meal);
		last_meal = arr_philo[i].last_meal;
		sem_post(semaphore->sem_last_meal);
		sem_wait(semaphore->sem_times_to_eat);
		is_done_eat = arr_philo[i].times_ate == param->times_must_to_eat;
		sem_post(semaphore->sem_times_to_eat);
		is_time_to_die = cur_time - last_meal > param->time_to_die \
		&& last_meal != 0;
		if (is_time_to_die && !is_done_eat)
			return (arr_philo[i].index_philo);
		i++;
	}
	return (-1);
}

int is_all_philo_done_eat(t_philosopher *arr_philo, t_parameters *param,
						t_semaphore *semaphore)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (param->nbr_philosophers != i)
	{
		sem_wait(semaphore->sem_times_to_eat);
		if (arr_philo[i].times_ate == param->times_must_to_eat)
			count++;
		sem_post(semaphore->sem_times_to_eat);
		i++;
	}
	return (count == param->nbr_philosophers);
}

void	*is_philosopher_death(void *arg)
{
	int				index_died_philo;
	t_self			*self;
	t_philosopher	*arr_philo;

	self = arg;
	arr_philo = self->arr_philo;
	while (wait_philo_sit_to_table(arr_philo, self->param))
		;
	while (1)
	{
		index_died_philo = is_philo_died(arr_philo, self->param, self->semaphore);
		if (index_died_philo != -1)
		{
			print_philo_message(&arr_philo[index_died_philo], \
			self->semaphore, DIED);
			sem_wait(self->semaphore->print_sem);
			return (NULL);
		}
		if (is_all_philo_done_eat(arr_philo, self->param, self->semaphore))
		{
			print_times_ate(arr_philo, self->param);
			return (NULL);
		}
	}
}
