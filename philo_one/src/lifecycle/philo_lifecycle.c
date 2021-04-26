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
	printf("I am a philo - %d | %s - %ld\n", philo->number_of_philo, message, get_current_time() - philo->start_time);
}

void			*is_philosopher_death(void *arg)
{
	int i;
	t_philosopher *arr_philo;

	arr_philo = arg;
	i = 0;
	while (arr_philo->param->nbr_philosophers != i)
	{
		wait_philo_sit_to_table(&arr_philo[i]);
		i++;
	}
	while (1)
	{
		i = 0;
		while (arr_philo->param->nbr_philosophers != i)
		{
			if (get_current_time() - arr_philo[i].last_meal >= arr_philo->param->time_to_die && arr_philo[i].last_meal != 0)
			{
				arr_philo[i].state = DIED;
				printf("Philo - %d DIED\n", arr_philo[i].number_of_philo);
				printf("curtime = %ld | last_meal = %ld | time_to_die = %ld\n" ,
					   get_current_time(), arr_philo[i].last_meal, arr_philo->param->time_to_die);
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
//	struct timeval	time;

	philo = arg;
	wait_philo_sit_to_table(philo);
	philo->last_meal = get_current_time();
	philo->start_time = philo->last_meal;
	while (1)
	{
		get_fork(philo);
//		gettimeofday(&time, NULL);
		philo->last_meal = get_current_time();//time.tv_sec * 1000 + time.tv_usec / 1000;
		print_message(philo, "EATING");
		my_usleep(philo->param->time_to_eat);
		put_fork(philo);
		print_message(philo, "SLEEPING");
		my_usleep(philo->param->time_to_sleep);
		print_message(philo, "THINKING");
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