/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/25 16:03:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->philo_id % 2 == 0)
		usleep(1000);

	pthread_mutex_lock(&(data->mutex_eat));
	while (!(data->is_dead) && !(data->end))
	{
		pthread_mutex_unlock(&(data->mutex_eat));
		eat_philosopher(philo);
		pthread_mutex_lock(&(data->mutex_eat));
		print_status(data, philo->philo_id, "is sleeping");
		pthread_mutex_unlock(&(data->mutex_eat));
		sleep_time(data->tts, data);
		pthread_mutex_lock(&(data->mutex_eat));
		print_status(data, philo->philo_id, "is thinking");

		// Vérifie si le philosophe a atteint sa limite de repas
		if (philo->meals >= data->meal_limit && !philo->full)
		{
			philo->full = true;
			data->check_eat++;
		}

		// Si tous les philosophes ont mangé assez, on arrête
		if (data->check_eat == data->nbr_philo)
		{
			data->end = true;
			pthread_mutex_unlock(&(data->mutex_eat));
			break;
		}
	}
	pthread_mutex_unlock(&(data->mutex_eat));
	return (NULL);
}



void	eat_philosopher(t_philo *philo)
{
	t_data	*data;

	data = philo->data;

	// Prise des fourchettes
	pthread_mutex_lock(&(data->forks[philo->left_fork->fork_id - 1].fork));
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "has taken a fork");
	pthread_mutex_unlock(&(data->mutex_eat));

	pthread_mutex_lock(&(data->forks[philo->right_fork->fork_id - 1].fork));
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "has taken a fork");
	print_status(data, philo->philo_id, "is eating");

	// Mise à jour de l’heure du dernier repas et augmentation du compteur de repas
	philo->time_since_meal = get_time();
	pthread_mutex_unlock(&(data->mutex_eat));

	// Philosophe mange pour une durée `tte`
	sleep_time(data->tte, data);

	pthread_mutex_lock(&(data->mutex_eat));
	(philo->meals)++;
	pthread_mutex_unlock(&(data->mutex_eat));

	// Libération des fourchettes
	pthread_mutex_unlock(&(data->forks[philo->right_fork->fork_id - 1].fork));
	pthread_mutex_unlock(&(data->forks[philo->left_fork->fork_id - 1].fork));
}

void	sleep_time(long long time, t_data *data)
{
	long long	start_time;

	start_time = get_time();
	pthread_mutex_lock(&(data->mutex_eat));
	while ((get_time() - start_time) < time && !(data->is_dead))
	{
		pthread_mutex_unlock(&(data->mutex_eat));
		usleep(50);
		pthread_mutex_lock(&(data->mutex_eat));
	}
	pthread_mutex_unlock(&(data->mutex_eat));
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
