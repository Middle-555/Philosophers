/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/03 16:45:13 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief Initialisation des données importantes.
 * 
 * @param data 
 */
void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->nbr_philo);
	data->forks = safe_malloc(sizeof(t_fork) * data->nbr_philo);
	while (i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		i++;
	}
}

/**
 * @brief  Initialisation des philos + fork assignement
 * 
 * @param data 
 */

void	init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo = data->philos + i;
		philo->philo_id = i + 1;
		philo->meals = 0;
		philo->full = false;
		fork_assignement(&data->philos[i], data, i);
		i++;
	}
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
	if (id % 2 == 0)
	{
		philo->left_fork = &data->forks[id];
		philo->right_fork = &data->forks[(id + 1) % data->nbr_philo];
	}
	else
	{
		philo->right_fork = &data->forks[id];
		philo->left_fork = &data->forks[(id + 1) % data->nbr_philo];
	}
}
