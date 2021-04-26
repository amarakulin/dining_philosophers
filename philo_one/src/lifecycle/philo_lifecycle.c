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

void			print_message(struct timeval time, t_philosopher *philo, char *message)
{
	long int curr_time;

	gettimeofday(&time, NULL);
	curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("I am a philo - %d | %s - %ld\n", philo->number_of_philo, message, curr_time - philo->start_time);
}

void			*is_philosopher_death(void *arg)
{
	int i;
	t_philosopher *arr_philo;
	struct timeval time;
	long int curr_time;

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
			gettimeofday(&time, NULL);
			curr_time = time.tv_sec * 1000 + time.tv_usec / 1000;
			if (curr_time - arr_philo[i].last_meal >= arr_philo->param->time_to_die && arr_philo[i].last_meal != 0)
			{
				arr_philo[i].state = DIED;
				printf("Philo - %d DIED\n", arr_philo[i].number_of_philo);
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
	struct timeval	time;
	long int		curr_time;

	philo = arg;
	wait_philo_sit_to_table(philo);
	gettimeofday(&time, NULL); // TODO protect may be
	philo->last_meal = time.tv_sec * 1000 + time.tv_usec / 1000;
	philo->start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (1)
	{
		get_fork(philo);
		gettimeofday(&time, NULL);
		philo->last_meal = time.tv_sec * 1000 + time.tv_usec / 1000;
		print_message(time, philo, "EATING");
		my_usleep(philo->param->time_to_eat);
		put_fork(philo);
		print_message(time, philo, "SLEEPING");
		my_usleep(philo->param->time_to_sleep);
		print_message(time, philo, "THINKING");
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