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

const char *philo_msg[4] = {"has taken a fork",
							"is eating",
							"is sleeping",
							"is thinking"};

void		print_philo_message(t_philosopher *philo, t_action_philo action)
{
	pthread_mutex_lock(&philo->param->print_mutex);
	printf("I am a philo - %d | %ld - %s\n", philo->index_philo + 1, get_current_time(), philo_msg[action]);
	pthread_mutex_unlock(&philo->param->print_mutex);
}

int		all_philo_done_eat(t_philosopher *arr_philo)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (arr_philo->param->nbr_philosophers != i)
	{
		pthread_mutex_lock(arr_philo[i].mutex_times_ate);
		if (arr_philo[i].times_ate == arr_philo->param->times_must_to_eat)
			count++;
		pthread_mutex_unlock(arr_philo[i].mutex_times_ate);
		i++;
	}
	return (count == arr_philo->param->nbr_philosophers);
}

void			*is_philosopher_death(void *arg)
{
	int i;
	t_philosopher *arr_philo;
	int main_condition;
	int is_done_eat;
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
			pthread_mutex_lock(arr_philo[i].mutex_last_meal);
			last_meal = arr_philo[i].last_meal;
			pthread_mutex_unlock(arr_philo[i].mutex_last_meal);
			pthread_mutex_lock(arr_philo[i].mutex_times_ate);
			is_done_eat = arr_philo[i].times_ate == arr_philo->param->times_must_to_eat;
			pthread_mutex_unlock(arr_philo[i].mutex_times_ate);
			main_condition = cur_time - last_meal > arr_philo->param->time_to_die && last_meal != 0;
			if (main_condition && !is_done_eat)
			{
				printf("Philo - %d DIED | i - %d\n", arr_philo[i].index_philo, i);
				return (NULL);
			}
			i++;
		}
		if (all_philo_done_eat(arr_philo))
		{
			i = 0;
			while (arr_philo->param->nbr_philosophers != i)
			{
				printf("Philo - %d ATE %d times \n", arr_philo[i].index_philo, arr_philo[i].times_ate);
				i++;
			}
			return (NULL);
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
		print_philo_message(philo, TAKEN_FORK);
		print_philo_message(philo, EATING);
		my_usleep(philo->param->time_to_eat);
		put_fork(philo);
		pthread_mutex_lock(philo->mutex_times_ate);
		philo->times_ate++;
		pthread_mutex_unlock(philo->mutex_times_ate);
		if (philo->times_ate == philo->param->times_must_to_eat)
			return NULL;
		print_philo_message(philo, SLEEPING);
		my_usleep(philo->param->time_to_sleep);
		print_philo_message(philo, THINKING);
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