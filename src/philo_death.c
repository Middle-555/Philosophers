/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:59:10 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/24 16:01:14 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_death(t_data *data)
{
	int			i;
	long long	current_time;

	i = 0;
	while (i < data->nbr_philo && !data->is_dead)
	{
		pthread_mutex_lock(&data->mutex_eat);
		current_time = get_time();
		if ((current_time - data->philos[i].time_since_meal) > data->ttd)
		{
			pthread_mutex_unlock(&data->mutex_eat);
			print_status(data, data->philos[i].philo_id, "is dead");
			data->is_dead = 1;
			break ;
		}
		pthread_mutex_unlock(&data->mutex_eat);
		i++;
	}
}

void	monitor_philos(t_data *data)
{
	while (!data->is_dead)
	{
		check_death(data);
		usleep(1000);
	}
	end_simulation(data);
}
