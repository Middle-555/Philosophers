/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:26 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philos)
		return (NULL);
	data->forks = malloc(sizeof(t_fork) * data->nbr_philo);
	if (!data->forks)
		return (NULL);
}
