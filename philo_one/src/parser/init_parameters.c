/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:27:27 by tilda             #+#    #+#             */
/*   Updated: 2021/04/21 14:27:29 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_parameters	*get_parameters(int argc, char *argv[])
{
	char **copy_argv;
	t_parameters *parameters;

	parameters = ft_calloc(sizeof(t_parameters),1);
	copy_argv = argv;
	parameters->nbr_philosophers = ft_atoi(copy_argv[1]);
	parameters->time_to_die = ft_atoi(copy_argv[2]);
	parameters->time_to_eat = ft_atoi(copy_argv[3]);
	parameters->time_to_sleep = ft_atoi(copy_argv[4]);
	if (argc == 6)
		parameters->times_must_to_eat = ft_atoi(copy_argv[5]); //at least they could eat 0 times
	else
		parameters->times_must_to_eat = -1;
	return (parameters);
}