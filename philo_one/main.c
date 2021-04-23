/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:53:28 by tilda             #+#    #+#             */
/*   Updated: 2021/04/20 19:53:29 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		main(int argc, char *argv[]){

	t_data			*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!is_validate_parametrs(argc, argv))
		return (1);
	data->param = get_parameters(argc, argv);
	data->arr_philo = init_philosophers(data->param);
	printf("Before Threads\n");
	create_philo_threads(data);
	printf("After Threads\n");
	free(data->param);
	free(data->arr_philo);
	return (0);
}
