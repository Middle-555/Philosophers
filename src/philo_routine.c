/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/12 14:05:10 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;

	pthread_mutex_lock(&(data->mutex_start));
	data->start = get_time();
	pthread_mutex_unlock(&(data->mutex_start));

	if (philo->philo_id % 2 == 0)
		usleep(500);

	while (1)
	{
		if (should_exit(philo))
			break;

		perform_actions(philo);
	}
	return (NULL);
}

int	should_exit(t_philo *philo)
{
	t_data	*data;
	int		exit;

	data = philo->data;
	pthread_mutex_lock(&(data->mutex_eat));
	exit = data->is_dead || data->end;
	pthread_mutex_unlock(&(data->mutex_eat));
	return (exit);
}

void	perform_actions(t_philo *philo)
{
	eat_philosopher(philo);
	print_status(philo->data, philo->philo_id, "is sleeping");
	sleep_time(philo->data->tts, philo->data);
	print_status(philo->data, philo->philo_id, "is thinking");
}
void	sleep_time(long long time, t_data *data)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		pthread_mutex_lock(&(data->mutex_eat));
		if (data->is_dead || data->end)
		{
			pthread_mutex_unlock(&(data->mutex_eat));
			break;
		}
		pthread_mutex_unlock(&(data->mutex_eat));
		usleep(50); // Pause courte pour éviter de surcharger le CPU
	}
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

int	check_meal_count(t_data *data)
{
	int	i;
	int	all_done;

	i = 0;
	all_done = 1;
	pthread_mutex_lock(&(data->mutex_eat));
	while (i < data->nbr_philo)
	{
		if (data->philos[i].meals < data->meal_limit)
		{
			all_done = 0; // Un philosophe n'a pas encore atteint la limite
			break;
		}
		i++;
	}
	if (all_done)
		data->end = 1; // Tous les philosophes ont mangé suffisamment
	pthread_mutex_unlock(&(data->mutex_eat));
	return (all_done);
}

