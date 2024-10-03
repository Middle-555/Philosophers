/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/03 17:10:02 by kpourcel         ###   ########.fr       */
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
		data->forks[i].fork_id = i + 1;
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			error_msg("Mutex initialization failed");
		i++;
	}
	test_forks(data);
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
		philo->data = data;
		philo->full = false;
		fork_assignement(&data->philos[i], data, i);
		i++;
	}
	test_philos(data);
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
	philo->left_fork = &data->forks[id];
	philo->right_fork = &data->forks[(id + 1) % data->nbr_philo];
}
