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

t_philosopher	*init_philosophers(t_parameters *param)
{
	size_t				i;
	t_philosopher	*arr_philosophers;

	i = 0;
	arr_philosophers = ft_calloc(param->nbr_philosophers, sizeof(t_philosopher));
	while(i != param->nbr_philosophers)
	{
		arr_philosophers[i].state = START_SIMULATION;
		arr_philosophers[i].last_meal = 0;
		arr_philosophers[i].numberOfPhilo = (int)i;
		i++;
	}
	return (arr_philosophers);
}

int				is_philosopher_death(t_philosopher *philo)
{
	if (philo->state == DIED)
		return (0);
	return (1);
}

void			*philo_lifecycle(void *arg)
{
	t_philosopher *philo;

	philo = arg;
	printf("I am a philo - %d\n", philo->numberOfPhilo);
	return (NULL);
}

void			create_philo_threads(t_philosopher *arr_philo, t_parameters *param)
{
	size_t	i;
	t_philosopher philo;

	i = 0;
	while (i != param->nbr_philosophers)
	{
		philo = arr_philo[i];
		pthread_create(&philo.thread_id, NULL, philo_lifecycle, &philo);
		pthread_join(philo.thread_id, NULL);
		i++;
	}
}