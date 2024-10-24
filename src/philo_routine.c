/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/24 16:06:08 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
/*
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
		pthread_mutex_lock(&philo->left_fork->fork);
		pthread_mutex_lock(&philo->right_fork->fork);
		printf("Philosopher %d is eating\n", philo->philo_id);
		usleep(philo->data->tte * 1000);
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
		printf("Philisopher %d is thinking", philo->philo_id);
		printf("Philosopher %d is sleeping\n", philo->philo_id);
		usleep(philo->data->tts * 1000);
	}
	return (NULL);
}
*/