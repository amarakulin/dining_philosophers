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

	t_parameters *parametrs;

	printf("%d\n", argc);
	if (!is_validate_parametrs(argc, argv))
		return (1);
	parametrs = get_parameters(argc, argv);

	free(parametrs);
	return (0);
}
