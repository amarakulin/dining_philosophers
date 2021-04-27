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

void		print_message(t_philosopher *philo, char *message)
{
	pthread_mutex_lock(&philo->param->print_mutex);
	printf("I am a philo - %d | %s - %ld\n", philo->index_philo + 1, message, get_current_time());
	pthread_mutex_unlock(&philo->param->print_mutex);
}

void			*is_philosopher_death(void *arg)
{
	int i;
	t_philosopher *arr_philo;
	int main_condition;
	long int cur_time;
	long int last_meal;

	arr_philo = arg;
	while (wait_philo_sit_to_table(&arr_philo[0]));
	while (1)
	{
		i = 0;
		while (arr_philo->param->nbr_philosophers != i)
		{
			cur_time = get_current_time();
			pthread_mutex_lock(arr_philo[i].param->arr_mutex_last_meal);
			last_meal = arr_philo[i].last_meal;
			pthread_mutex_unlock(arr_philo[i].param->arr_mutex_last_meal);
			main_condition = cur_time - last_meal > arr_philo->param->time_to_die && last_meal != 0;
			if (main_condition)
			{
				printf("Philo - %d DIED | i - %d\n", arr_philo[i].index_philo, i);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void			*philo_lifecycle(void *arg)
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
		pthread_mutex_lock(philo->param->arr_mutex_last_meal);
		philo->last_meal = get_current_time();
		pthread_mutex_unlock(philo->param->arr_mutex_last_meal);
		print_message(philo, "has taken a fork");
		print_message(philo, "is eating");
		my_usleep(philo->param->time_to_eat);
		//Philo ate
		put_fork(philo);
		print_message(philo, "is sleeping");
		my_usleep(philo->param->time_to_sleep);
		print_message(philo, "is thinking");
	}
	return (NULL);
}

void			create_threads(t_parameters *param, t_philosopher *arr_philo)
{
	int				i;
	pthread_t		thread_death;

	i = 0;
	//TODO Create thread to print out in the terminal info
	pthread_create(&thread_death, NULL, is_philosopher_death, (void *)arr_philo);
	while (i != param->nbr_philosophers)
	{
		pthread_create(&arr_philo[i].thread_id, NULL, philo_lifecycle, (void *)&arr_philo[i]);
		i++;
	}
	pthread_join(thread_death, NULL);
}