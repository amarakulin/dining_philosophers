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
#import <unistd.h>
#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#include <pthread.h>
#include <sys/time.h>

//structures.h
#import "structures.h"




/*
** philo_lifecycle.c
*/
void			*is_philosopher_death(void *arg);
void			*philo_lifecycle(void *arg);
void			create_threads(t_parameters *param, t_philosopher *arr_philo);

/*
** philo_lifecycle.c
*/
void			wait_philo_sit_to_table(t_philosopher *philo);
int				my_usleep(useconds_t usec);

/*
** validate.c
*/
int				is_validate_parametrs(int argc, char *argv[]);

/*
** init.c
*/
t_parameters	*get_parameters(int argc, char *argv[]);
t_philosopher	*init_philosophers(t_parameters *param);

/*
** utils.c
*/
long long int	ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);



#endif