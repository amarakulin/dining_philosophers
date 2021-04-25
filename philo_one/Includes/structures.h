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
	SIT_TO_TABLE = 0,
	DIED = 1,
	THOUGHT = 2,
	SLEPT = 3,
	ATE = 4,
}			t_state_philosopher;

typedef struct s_parameters
{
	long int	nbr_philosophers;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	times_must_to_eat;
	char		*wait_all_philo;
	int			*fork_arr;
}				t_parameters;

typedef struct s_philosopher
{
	int						number_of_philo;
	int						is_right_fork;
	int						is_left_fork;
	long int				last_meal;
	pthread_t				thread_id;
	t_state_philosopher		state;
	t_parameters			*param;
}				t_philosopher;

#endif

