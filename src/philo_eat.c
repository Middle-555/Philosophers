/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:01:57 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/12 14:07:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat_philosopher(t_philo *philo)
{
	take_forks(philo);
	start_eating(philo);
	release_forks(philo);
}

void	take_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->left_fork->fork_id < philo->right_fork->fork_id)
	{
		pthread_mutex_lock(&(data->forks[philo->right_fork - data->forks].fork));
		print_status(data, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&(data->forks[philo->left_fork - data->forks].fork));
	}
	else
	{
		pthread_mutex_lock(&(data->forks[philo->left_fork - data->forks].fork));
		print_status(data, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&(data->forks[philo->right_fork - data->forks].fork));
	}
	print_status(data, philo->philo_id, "has taken a fork");
}

void	start_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "is eating");
	philo->time_since_meal = get_time();
	(philo->meals)++;
	pthread_mutex_unlock(&(data->mutex_eat));
	sleep_time(data->tte, data);
}

void	release_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&(data->forks[philo->right_fork - data->forks].fork));
	pthread_mutex_unlock(&(data->forks[philo->left_fork - data->forks].fork));
}
