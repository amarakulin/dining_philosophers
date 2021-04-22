/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:10:31 by tilda             #+#    #+#             */
/*   Updated: 2021/04/20 20:10:33 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _PHILO_ONE_H
#define _PHILO_ONE_H

//General headers
#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#include <pthread.h>

//structures.h
#import "structures.h"

t_philosopher	*init_philosophers(t_parameters *param);
int				is_philosopher_death(t_philosopher *philo);
void			*philo_lifecycle(void *arg);
void			create_philo_threads(t_philosopher *arr_philo, t_parameters *param);


/*
** validate.c
*/
int				is_validate_parametrs(int argc, char *argv[]);

/*
** init_parameters.c
*/
t_parameters	*get_parameters(int argc, char *argv[]);

/*
** utils.c
*/
long long int	ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);



#endif