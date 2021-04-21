/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:47:54 by tilda             #+#    #+#             */
/*   Updated: 2021/04/21 12:47:55 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		is_number(char *arg)
{
	int		i;
	char	*p_arg;

	i = 0;
	p_arg = arg;
	while(p_arg[i])
	{
		if (!is_digit(p_arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int		is_validate_parametrs(int argc, char *argv[])
{
	int		i;
	long long int number_arg;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("[-]Error : wrong number arguments\n");
		return (0);
	}
	while (argv[i])
	{
		if (!is_number(argv[i]))
		{
			printf("[-]Error : %s - is wrong argument\n", argv[i]);
			return (0);
		}
		number_arg = ft_atoi(argv[i]);
		if ((number_arg < 1 && i == 1) || (number_arg < 0))
		{
			printf("[-]Error : %s - is wrong number argument\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
