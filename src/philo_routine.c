/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 16:54:26 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)arg;
	data = philo->data;
	i = 0;
	while (!philo->data->end)
	{
		printf("Philosopher %d is thinking\n", philo->philo_id);
		pthread_mutex_lock(&philo->left_fork->fork);
		pthread_mutex_lock(&philo->right_fork->fork);
		printf("Philosopher %d is eating\n", philo->philo_id);
		usleep(philo->data->tte * 1000);
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
		printf("Philosopher %d is sleeping\n", philo->philo_id);
		usleep(philo->data->tts * 1000);
	}
	return (NULL);
}
