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

#include "philo_two.h"

const char	*g_error_msg[2] = {"wrong number arguments",
								 "- is wrong argument"};

void	print_error(int nbr_error, char *arg)
{
	if (nbr_error == 0)
		printf("[-]Error : %s\n", g_error_msg[nbr_error]);
	else if (nbr_error == 1)
		printf("[-]Error : %s %s\n", arg, g_error_msg[nbr_error]);
}

int	is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_number(char *arg)
{
	int		i;
	char	*p_arg;

	i = 0;
	p_arg = arg;
	while (p_arg[i])
	{
		if (!is_digit(p_arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_validate_parametrs(int argc, char *argv[])
{
	int			i;
	long int	value_arg;
	int			nbr_error;

	i = 1;
	nbr_error = -1;
	if (argc != 5 && argc != 6)
		nbr_error = 0;
	while (argv[i] && nbr_error == -1)
	{
		if (!is_number(argv[i]))
			nbr_error = 1;
		value_arg = ft_atoi(argv[i]);
		if (((value_arg < 1 || value_arg > 200) && i == 1) || (value_arg < 0))
			nbr_error = 1;
		i++;
	}
	print_error(nbr_error, argv[i - 1]);
	return (nbr_error);
}
