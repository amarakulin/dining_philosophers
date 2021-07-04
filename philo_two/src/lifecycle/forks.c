
#include "philo_two.h"

int	left(int position_philo, int total_philosophers)
{
	return ((position_philo + 1) % total_philosophers);
}

int	take_fork(t_philosopher *philo, t_semaphore *semaphore)
{
	sem_wait(semaphore->sem_fork);
	sem_wait(semaphore->sem_fork);
	sem_wait(semaphore->sem_last_meal);
	philo->last_meal = get_current_time();
	sem_post(semaphore->sem_last_meal);
	return (0);
}

int	put_fork(t_philosopher *philo, t_semaphore *semaphore, \
			int times_must_to_eat)
{
	sem_post(semaphore->sem_fork);
	sem_post(semaphore->sem_fork);
	sem_wait(semaphore->sem_times_to_eat);
	philo->times_ate++;
	sem_post(semaphore->sem_times_to_eat);
	if (philo->times_ate == times_must_to_eat)
		return (0);
	return (1);
}
