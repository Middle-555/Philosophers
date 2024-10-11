/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:09:21 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 15:22:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].time_since_meal = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nbr_philo];
		data->philos[i].data = data;
		data->philos[i].full = 0;
		i++;
	}
	return (0);
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
	return (1);
}
