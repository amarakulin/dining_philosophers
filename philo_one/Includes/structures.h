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
	DIED = 1,
	THINKING = 2,
	SLEEPING = 3,
	EATING = 4,
}			t_state_philosopher;

typedef struct s_parameters
{
	long int	nbr_philosophers;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	times_must_to_eat;
}				t_parameters;

typedef struct s_philosopher
{
	t_state_philosopher		state;
	long int				last_meal;
	pthread_t				thread_id;
	int 					numberOfPhilo;
	t_parameters			*param;
}				t_philosopher;

#endif

