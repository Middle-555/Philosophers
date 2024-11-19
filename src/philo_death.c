/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:59:10 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/19 17:44:05 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_death(t_data *data)
{
	int			i;
	long long	current_time;

	pthread_mutex_lock(&(data->mutex_eat));
	i = 0;
	while (i < data->nbr_philo)
	{
		current_time = get_time();
		if ((current_time - data->philos[i].time_since_meal) > data->ttd)
		{
			// Détecter la mort et marquer `is_dead`
			pthread_mutex_lock(&(data->mutex_check));
			data->is_dead = 1; // Écriture protégée
			pthread_mutex_unlock(&(data->mutex_check));
			pthread_mutex_unlock(&(data->mutex_eat));
			print_status(data, data->philos[i].philo_id, "is dead");
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&(data->mutex_eat));
}


void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (!data)
	{
		error_msg("Invalid data");
		return (NULL);
	}
	while (!data->is_dead && !data->end)
	{
		check_death(data);
		check_meal_count(data); // Vérifie si tous les philosophes ont mangé suffisamment
		usleep(50);
	}
	end_simulation(data);
	//cleanup(data);
	return (NULL);
}
/*
int	get_is_dead(t_data *data)
{

	pthread_mutex_lock(&(data->mutex_eat));
	data->is_dead; // Lecture protégée
	pthread_mutex_unlock(&(data->mutex_eat));
	return (is_dead);
}

void	set_is_dead(t_data *data, int value)
{
	//pthread_mutex_lock(&(data->mutex_eat));
	data->is_dead = value; // Écriture protégée
	//pthread_mutex_unlock(&(data->mutex_eat));
}
*/