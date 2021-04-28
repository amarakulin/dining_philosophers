/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:08:51 by tilda             #+#    #+#             */
/*   Updated: 2021/04/20 20:08:52 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum e_action_philo
{
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}				t_action_philo;

typedef struct s_parameters
{
	int					times_must_to_eat;
	int					nbr_philosophers;
	char				*wait_all_philo;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			time_to_die;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*arr_fork;
	pthread_mutex_t		*arr_times_to_eat;
	pthread_mutex_t		*arr_mutex_last_meal;
}						t_parameters;

typedef struct s_philosopher
{
	int					times_ate;
	int					index_philo;
	long int			last_meal;
	pthread_t			thread_id;
	t_parameters		*param;
	pthread_mutex_t		*is_right_fork;
	pthread_mutex_t		*is_left_fork;
	pthread_mutex_t		*mutex_last_meal;
	pthread_mutex_t		*mutex_times_ate;
}						t_philosopher;

#endif

