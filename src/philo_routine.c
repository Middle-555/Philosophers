/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/10 17:11:02 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep_and_think(t_philo *philo)
{
	long long	start_time;

	start_time = get_time();
	printf("Philo %d is sleeping\n", philo->philo_id);
	while (!philo->data->end && (get_time() - start_time < philo->data->tts))
		usleep(100);
	printf("Philo %d is thinking\n", philo->philo_id);
}

void	philo_eat(t_philo *philo)
{
	long long	start_time;

	start_time = get_time();
	philo->time_since_meal = start_time;
	printf("Philo %d is eating\n", philo->philo_id);
	while (!philo->data->end && (get_time() - start_time < philo->data->tte))
		usleep(100);
	philo->meals++;
}
