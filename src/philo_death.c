/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:59:10 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 17:59:04 by kpourcel         ###   ########.fr       */
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
			printf("Philosophe %d est mort : temps écoulé = %lld ms\n",
				   data->philos[i].philo_id, current_time - data->philos[i].time_since_meal);
			data->is_dead = 1;
			print_status(data, data->philos[i].philo_id, "is dead");
			pthread_mutex_unlock(&(data->mutex_eat));
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
	while (!data->is_dead)
	{
		check_death(data);
		usleep(100);
	}
	end_simulation(data);
	return (NULL);
}
