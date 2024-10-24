/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:01:57 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/24 16:19:28 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_eat);
	free(data->philos);
	free(data->forks);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos != NULL)
		free(data->philos);
	if (data->forks != NULL)
	{
		while (i < data->nbr_philo)
		{
			pthread_mutex_destroy(&data->forks[i].fork);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_eat);
}
