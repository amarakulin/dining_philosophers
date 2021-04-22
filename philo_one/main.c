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

	t_parameters *param;
	t_philosopher *arr_philo;

	printf("%d\n", argc);
	if (!is_validate_parametrs(argc, argv))
		return (1);
	param = get_parameters(argc, argv);
	arr_philo = init_philosophers(param);
	printf("Before Threads\n");
	create_philo_threads(arr_philo, param);
	printf("After Threads\n");
	free(param);
	free(arr_philo);
	return (0);
}
