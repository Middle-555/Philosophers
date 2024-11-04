/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:01:57 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 18:04:35 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_simulation(t_data *data)
{
	int	i;

	// Attendre la fin de tous les threads de philosophes
	i = 0;
	while (i < data->nbr_philo)
	{
		if (data->philos[i].thread_id) // Vérifie que le thread est valide
		{
			if (pthread_join(data->philos[i].thread_id, NULL) != 0)
				error_msg("Failed to join thread");
		}
		i++;
	}
	// Libération des ressources et destruction des mutex
	pthread_mutex_destroy(&(data->mutex_print));
	pthread_mutex_destroy(&(data->mutex_eat));
	pthread_mutex_destroy(&(data->mutex_start));
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&(data->forks[i].fork));
		i++;
	}
	free(data->forks);
	free(data->philos);
}



void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_eat);
	pthread_mutex_destroy(&data->mutex_start);
	free(data->philos);
	free(data->forks);
}
