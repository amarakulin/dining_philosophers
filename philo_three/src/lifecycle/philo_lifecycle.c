
#include "philo_three.h"

int	action_philo(t_philosopher *philo, t_parameters *param, \
	t_semaphore *semaphore)
{
	take_fork(philo, semaphore);
	print_philo_message(philo, param, semaphore, TAKEN_FORK);
	print_philo_message(philo, param, semaphore, EATING);
	my_usleep(param->time_to_eat);
	if (!put_fork(philo, semaphore, param->times_must_to_eat))
		return (0);
	print_philo_message(philo, param, semaphore, SLEEPING);
	my_usleep(param->time_to_sleep);
	print_philo_message(philo, param, semaphore, THINKING);
	return (1);
}

void	*philo_lifecycle(t_self *self, int i)
{
	t_philosopher	*philo;

	philo = &self->arr_philo[i];
	if (philo->index_philo % 2 == 0)
		my_usleep(10);
	sem_wait(self->semaphore->sem_last_meal);
	philo->last_meal = get_current_time();
	sem_post(self->semaphore->sem_last_meal);
	while (1)
	{
		if (!action_philo(philo, self->param, self->semaphore))
			exit (1);
	}
}

void	philo_process(t_self *self, int i)
{
	pthread_t		thread_death;

	pthread_create(&thread_death, NULL, is_philosopher_death, \
				(void *)constract_death_thread(self, i));
	philo_lifecycle(self, i);
	pthread_join(thread_death, NULL);
}

void	*parent_process(int nbr_philosophers, int *pids)
{
	int		status;
	int		i;
	int		res;

	i = 0;
	res = waitpid(0, &status, WUNTRACED);
	if (status == 48)
		return (NULL);
	else if (status == 256)
		kill(res, SIGKILL);
	else if (status == 0)
	{
		while (nbr_philosophers != i)
			kill(pids[i++], SIGKILL);
		return (NULL);
	}
	return (parent_process(nbr_philosophers, pids));
}

void	create_process(t_self *self)
{
	int	i;
	int	*pids;

	i = 0;
	pids = ft_calloc(self->param->nbr_philosophers, sizeof(int));
	self->param->time_start = get_current_time();
	while (i != self->param->nbr_philosophers)
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			printf("Error fork\n");
			exit(1);
		}
		else if (pids[i] == 0)
			philo_process(self, i);
		i++;
	}
	parent_process(self->param->nbr_philosophers, pids);
	free(pids);
}
