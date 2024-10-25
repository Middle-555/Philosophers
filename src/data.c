/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:09:21 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/25 15:34:48 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_data *data)
{
	int	i;

	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
		{
			error_msg("Failed to initialize mutex.");
			return (0);
		}
		data->forks[i].fork_id = i + 1;
		i++;
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int			i;

	if (!data->philos)
	{
		error_msg("Failed to allocate memory for philosophers.");
		return (0);
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].time_since_meal = get_time();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nbr_philo];
		data->philos[i].data = data;
		data->philos[i].full = 0;
		i++;
	}
	return (1);
}

int	fill_input(t_data *data, char **argv)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->ttd = ft_atol(argv[2]);
	data->tte = ft_atol(argv[3]);
	data->tts = ft_atol(argv[4]);
	if (argv[5] != NULL)
		data->meal_limit = ft_atol(argv[5]);
	else
		data->meal_limit = -1;
	data->forks = (t_fork *)safe_malloc(sizeof(t_fork) * data->nbr_philo);
	data->philos = (t_philo *)safe_malloc(sizeof(t_philo) * data->nbr_philo);
	return (1);
}

int	create_threads(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->mutex_start); // Bloquer avant la création des threads
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&(data->philos[i].thread_id), NULL,
				&philosopher_routine, &(data->philos[i])) != 0)
		{
			error_msg("Failed to create thread");
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&data->mutex_start); // Débloquer après la création des threads
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
		{
			error_msg("Failed to initialize mutex for fork");
			return (0);
		}
		i++;
	}
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0
		|| pthread_mutex_init(&data->mutex_eat, NULL) != 0
		|| pthread_mutex_init(&data->mutex_start, NULL) != 0) // Initialisation de mutex_start
	{
		error_msg("Failed to initialize mutex");
		return (0);
	}
	return (1);
}
