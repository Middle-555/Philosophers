/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/10 17:10:38 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (!philo->data->end)
	{
		// Vérifier si le philosophe est mort
		if (get_time() - philo->time_since_meal > philo->data->ttd)
		{
			philo->data->end = true;
			printf("Philo %d died\n", philo->philo_id);
			return (NULL);
		}
		// Prendre les fourchettes
		if (!take_forks(philo))
			break ;
		// Manger
		philo_eat(philo);
		// Relâcher les fourchettes
		release_forks(philo);
		// Dormir et penser
		philo_sleep_and_think(philo);
	}
	return (NULL);
}


int	initialize_program(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (0);
	}
	if (!fill_input(data, argv))
	{
		printf("Error: Failed to fill input data\n");
		return (0);
	}
	if (!init_data(data))
	{
		printf("Error: Failed to initialize data\n");
		return (0);
	}
	if (!init_philo(data))
	{
		printf("Error: Failed to initialize philosophers\n");
		return (0);
	}
	return (1);
}

int	start_dinner(t_data *data)
{
	int	i;

	data->start = get_time();
	if (pthread_create(&data->monitor_thread, NULL, monitor_philosophers, data) != 0)
	{
		printf("Error: Failed to create the monitor thread\n");
		return (0);
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, philo_routine, &data->philos[i]) != 0)
		{
			printf("Error: Failed to create philosopher %d thread\n", i + 1);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(data->monitor_thread, NULL);
	return (1);
}

void	*monitor_philosophers(void *arg)
{
	int		i;
	long	current_time;
	t_data	*data;

	data = (t_data *)arg;
	while (!data->end)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			current_time = get_time();
			if (current_time - data->philos[i].time_since_meal >= data->ttd)
			{
				data->end = true;
				printf("Philo %d died\n", data->philos[i].philo_id);
				return (NULL);
			}
			if (data->philos[i].full)
				data->end = true;
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->fork));
	printf("Philo %d took left fork %d\n", philo->philo_id, philo->left_fork->fork_id);
	pthread_mutex_lock(&(philo->right_fork->fork));
	printf("Philo %d took right fork %d\n", philo->philo_id, philo->right_fork->fork_id);
	return (1);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->fork));
	pthread_mutex_unlock(&(philo->right_fork->fork));
}
