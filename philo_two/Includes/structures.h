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
# define STRUCTURES_H

typedef enum e_action_philo
{
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}				t_action_philo;

typedef struct s_semaphore
{
	sem_t		*print_sem;
	sem_t		*sem_fork;
	sem_t		*sem_times_to_eat;
	sem_t		*sem_last_meal;
}				t_semaphore;

typedef struct s_parameters
{
	int					nbr_philosophers;
	char				*wait_all_philo;
	int					times_must_to_eat;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			time_to_die;
}						t_parameters;

typedef struct s_philosopher
{
	int					times_ate;
	int					index_philo;
	long int			last_meal;
	pthread_t			thread_id;
}						t_philosopher;

typedef struct s_self
{
	t_philosopher	*arr_philo;
	t_parameters	*param;
	t_semaphore		*semaphore;
}				t_self;

typedef struct s_lifecycle
{
	t_self		*self;
	int			index_philo;
}				t_lifecycle;

#endif
