
#include "philo_one.h"

void	clear_all_malloc(t_self *self)
{
	free(self->param->wait_all_philo);
	free(self->param);
	free(self->arr_philo);
	free(self->mutex->arr_fork);
	free(self->mutex->arr_last_meal);
	free(self->mutex->arr_times_to_eat);
	free(self->mutex);
	free(self);
}

long int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = malloc(count * size);
	memset(memory, 0, count * size);
	return (memory);
}

void	skip_symbols(const char **str, int *flag_minus)
{
	char	*p_str;

	p_str = (char *)*str;
	while ((*p_str >= 9 && *p_str <= 13) || (*p_str == 32) || (*p_str == 48))
		p_str++;
	if (*p_str == '-' || *p_str == '+')
	{
		if (*p_str == '-')
			*flag_minus = -1;
		p_str++;
	}
}

long long int	ft_atoi(const char *str)
{
	long long int	res;
	int				flag_minus;

	flag_minus = 1;
	res = 0;
	skip_symbols(&str, &flag_minus);
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 < res)
		{
			if (res * flag_minus > 0)
				return (-1);
			else
				return (0);
		}
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * flag_minus);
}
