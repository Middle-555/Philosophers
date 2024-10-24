/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/24 18:09:19 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	//int		i;

	philo = (t_philo *)arg;
	data = philo->data;
	//i = 0;
	while (!philo->data->end)
	{
		print_status(data, philo->philo_id, "is thinking");
		pthread_mutex_lock(&philo->left_fork->fork);
		print_status(data, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->fork);
		print_status(data, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&data->mutex_eat);
		print_status(data, philo->philo_id, "is eating");
		philo->time_since_meal = get_time();
		pthread_mutex_unlock(&data->mutex_eat);
		print_status(data, philo->philo_id, "is sleeping");
		usleep(data->tts * 1000);
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
	}
	return (NULL);
}

int	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
		{
			error_msg("Failed to join thread");
			return (0);
		}
		i++;
	}
	return (1);
}
