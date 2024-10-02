/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/02 16:03:33 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_data(t_data *data)
{
	//int	i;
	//i = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->nbr_philo);
	data->forks = safe_malloc(sizeof(t_fork) * data->nbr_philo);
}

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
		i++;
	}
}
/*
void	fork_assignement(t_philo *philo, t_data *data, int pos)
{
	//t_fork	*fork;

	philo->left_fork = philo->philo_id + 1 % data->nbr_philo;
	philo->right_fork = philo->philo_id;
}
*/