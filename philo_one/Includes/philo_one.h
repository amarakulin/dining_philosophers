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

//structures.h
#import "structures.h"

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