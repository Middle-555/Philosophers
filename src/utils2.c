/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:00:24 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 15:40:38 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// malloc + check
void	*safe_malloc(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
		error_msg("Malloc error");
	return (dst);
}

// tv_sec = numbers of second since 1rst january 1970
// tv_usec = numbers of microsecond since the last second
// everything is converd to milliseconds.
long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

// Exemple de libération des ressources à la fin

void	cleanup(t_data *data)
{
	int	i;

	if (data->philos != NULL)
		free(data->philos);
	if (data->forks != NULL)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			pthread_mutex_destroy(&data->forks[i].fork);
			i++;
		}
		free(data->forks);
	}
}