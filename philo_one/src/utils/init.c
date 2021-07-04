
#include "philo_one.h"

t_mutex	*init_mutex(t_parameters *param)
{
	int		i;
	t_mutex	*mutex;

	i = 0;
	mutex = ft_calloc(1, sizeof(t_mutex));
	mutex->arr_fork = ft_calloc(sizeof(pthread_mutex_t), \
	param->nbr_philosophers);
	mutex->arr_times_to_eat = ft_calloc(sizeof(pthread_mutex_t), \
	param->nbr_philosophers);
	mutex->arr_last_meal = ft_calloc(sizeof(pthread_mutex_t), \
	param->nbr_philosophers);
	while (i != param->nbr_philosophers)
	{
		pthread_mutex_init(&mutex->arr_fork[i], NULL);
		pthread_mutex_init(&mutex->arr_last_meal[i], NULL);
		pthread_mutex_init(&mutex->arr_times_to_eat[i], NULL);
		i++;
	}
	pthread_mutex_init(&mutex->print_mutex, NULL);
	return (mutex);
}

t_philosopher	*init_philosophers(t_parameters *param, t_mutex *mutex)
{
	int				i;
	t_philosopher	*arr_philosophers;

	i = 0;
	arr_philosophers = ft_calloc(param->nbr_philosophers, \
	sizeof(t_philosopher));
	while (i != param->nbr_philosophers)
	{
		arr_philosophers[i].index_philo = i;
		arr_philosophers[i].times_ate = 0;
		arr_philosophers[i].last_meal = 0;
		arr_philosophers[i].is_right_fork = &mutex->arr_fork[i];
		arr_philosophers[i].is_left_fork = &mutex->arr_fork[left(
				i, param->nbr_philosophers)];
		arr_philosophers[i].mutex_last_meal = &mutex->arr_last_meal[i];
		arr_philosophers[i].mutex_times_ate = &mutex->arr_times_to_eat[i];
		i++;
	}
	return (arr_philosophers);
}

t_parameters	*get_parameters(int argc, char *argv[])
{
	t_parameters	*param;

	param = ft_calloc(sizeof(t_parameters), 1);
	param->nbr_philosophers = (int)ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		param->times_must_to_eat = (int)ft_atoi(argv[5]);
	else
		param->times_must_to_eat = -1;
	param->wait_all_philo = ft_calloc(sizeof(char), \
	param->nbr_philosophers + 1);
	return (param);
}
