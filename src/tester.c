/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:50:09 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 14:35:03 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	test_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		printf("Fork %d initialized with ID %d\n", i + 1,
			data->forks[i].fork_id);
		i++;
	}
}

void	test_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo = &data->philos[i];
		printf("Philo %d initialized with left fork %d and right fork %d\n",
			philo->philo_id, philo->left_fork->fork_id,
			philo->right_fork->fork_id);
		if (philo->left_fork == philo->right_fork)
		{
			error_msg("Error: Philosopher has the same fork assigned twice!");
		}
		i++;
	}
}
