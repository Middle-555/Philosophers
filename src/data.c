/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:09:21 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/10 17:03:47 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief Initialisation des données importantes.
 * 
 * @param data 
 */

int	init_data(t_data *data)
{
	data->forks = malloc(sizeof(t_fork) * data->nbr_philo);
	if (!data->forks)
	{
		printf("Error: Memory allocation failed for forks\n");
		return (0);
	}
	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philos)
	{
		free(data->forks);
		printf("Error: Memory allocation failed for philosophers\n");
		return (0);
	}
	data->end = false;
	return (1);
}

/**
 * @brief  Initialisation des philos + fork assignement
 * 
 * @param data 
 */

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].full = false;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nbr_philo];
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
		{
			printf("Error: Failed to initialize fork %d\n", i + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief Assignation des fourchettes en fonction de l'id du philo Pair ou impair
 * 
 * @param philo 
 * @param data 
 * @param id 
 */

void	fork_assignement(t_philo *philo, t_data *data, int id)
{
	if (!data || !data->forks)
	{
		error_msg("Invalid data or forks array");
		return ;
	}
	philo->left_fork = &data->forks[id];
	philo->right_fork = &data->forks[(id + 1) % data->nbr_philo];
}
