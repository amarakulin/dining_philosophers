
#include "philo_two.h"

const char	*g_philo_msg[5] = {"has taken a fork",
							  "is eating",
							  "is sleeping",
							  "is thinking",
							  "died"};

void	print_philo_message(t_philosopher *philo, t_parameters *param, \
							t_semaphore *semaphore, t_action_philo action)
{
	if (action == DIED)
	{
		sem_wait(semaphore->print_sem);
		printf("%ld %d %s\n", get_current_time() - param->start_time, philo->index_philo + 1, \
		g_philo_msg[action]);
	}
	else
	{
		sem_wait(semaphore->print_sem);
		printf("%ld %d %s\n", get_current_time() - param->start_time, philo->index_philo + 1, \
		g_philo_msg[action]);
		sem_post(semaphore->print_sem);
	}
}

int	my_usleep(useconds_t usec)
{
	long int	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < usec && usec > 100)
	{
		if (usleep(100) == -1)
			return (-1);
	}
	if (usec < 100)
		usleep(usec);
	return (0);
}
