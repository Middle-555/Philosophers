/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:50:09 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 15:59:29 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	test_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		printf("Fork %d initialized with ID %d\n",
			i + 1, data->forks[i].fork_id);
		i++;
	}
}

void	test_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		printf("Philo %d initialized with left fork %d and right fork %d\n",
			data->philos[i].philo_id,
			data->philos[i].left_fork->fork_id,
			data->philos[i].right_fork->fork_id);
		i++;
	}
}

void	test_fill_input(t_data *data)
{
	printf("Number of philosophers: %ld\n", data->nbr_philo);
	printf("Time to die: %ld ms\n", data->ttd);
	printf("Time to eat: %ld ms\n", data->tte);
	printf("Time to sleep: %ld ms\n", data->tts);
	if (data->meal_limit == -1)
		printf("Meal limit: No limit\n");
	else
		printf("Meal limit: %ld\n", data->meal_limit);
}
