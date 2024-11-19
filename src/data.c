/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:09:21 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/19 17:40:49 by kpourcel         ###   ########.fr       */
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

	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philos)
	{
		fprintf(stderr, "Failed to allocate philos array\n");
		return(0);
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
		data->is_dead = 0;
		data->start = get_time();
		data->end = false;
		i++;
	}
	printf("Philos array initialized successfully\n");
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
	return (1);
}

int	create_threads(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&(data->philos[i].thread_id), NULL,
				&philosopher_routine, &(data->philos[i])) != 0)
		{
			error_msg("Failed to create thread");
			while (--i >= 0)
				pthread_join(data->philos[i].thread_id, NULL);
			return (0);
		}
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, &monitor_routine, (void *)data) != 0)
	{
		error_msg("Failed to create monitoring thread");
		while (--i >= 0)
			pthread_join(data->philos[i].thread_id, NULL);
		return (0);
	}
	pthread_join(monitor_thread, NULL);
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
		|| pthread_mutex_init(&data->mutex_start, NULL) != 0
		|| pthread_mutex_init(&data->mutex_check, NULL) != 0)
	{
		error_msg("Failed to initialize mutex");
		return (0);
	}
	return (1);
}
