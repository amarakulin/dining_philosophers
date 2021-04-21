/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:42:03 by tilda             #+#    #+#             */
/*   Updated: 2021/04/21 13:42:04 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *memory;

	memory = malloc(count * size);
	memset(memory, 0, count * size);
	return (memory);
}


long long int	ft_atoi(const char *str)
{
	long long int	res;
	int				flag_minus;

	flag_minus = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32) || (*str == 48))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag_minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 < res)
			return ((res * flag_minus > 0) ? -1 : 0);
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * flag_minus);
}