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

typedef enum e_state_philosopher
{
	START_SIMULATION = 0,
	READY = 1,
}			t_state_philosopher;

typedef struct s_parameters
{
	int					nbr_philosophers;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			times_must_to_eat;
	char				*wait_all_philo;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*arr_mutex_last_meal;
	pthread_mutex_t		*fork_arr;
}				t_parameters;

typedef struct s_philosopher
{
	int						index_philo;
	pthread_mutex_t			*is_right_fork;
	pthread_mutex_t			*is_left_fork;
	pthread_mutex_t			*mutex_last_meal;
	long int				last_meal;
	pthread_t				thread_id;
	t_parameters			*param;
}				t_philosopher;

#endif

