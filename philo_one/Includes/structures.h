
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

typedef struct s_mutex
{
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*arr_fork;
	pthread_mutex_t		*arr_times_to_eat;
	pthread_mutex_t		*arr_last_meal;
}				t_mutex;

typedef struct s_parameters
{
	int					nbr_philosophers;
	char				*wait_all_philo;
	int					times_must_to_eat;
	long int			start_time;
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
	pthread_mutex_t		*is_right_fork;
	pthread_mutex_t		*is_left_fork;
	pthread_mutex_t		*mutex_last_meal;
	pthread_mutex_t		*mutex_times_ate;
}						t_philosopher;

typedef struct s_self
{
	t_philosopher	*arr_philo;
	t_parameters	*param;
	t_mutex			*mutex;
}				t_self;

typedef struct s_lifecycle
{
	t_self		*self;
	int			index_philo;
}				t_lifecycle;

#endif
