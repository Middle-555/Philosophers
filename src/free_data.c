/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:01:57 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/19 16:23:39 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void end_simulation(t_data *data)
{
    if (!data) 
    {
        fprintf(stderr, "Data is NULL\n");
        return;
    }
    if (!data->philos) 
    {
        fprintf(stderr, "Philos array is NULL\n");
        return;
    }
    if (!data->forks) 
    {
        fprintf(stderr, "Forks array is NULL\n");
        return;
    }

    wait_for_threads(data);

    if (pthread_mutex_destroy(&(data->mutex_print)) != 0)
        fprintf(stderr, "Failed to destroy mutex_print\n");
    if (pthread_mutex_destroy(&(data->mutex_eat)) != 0)
        fprintf(stderr, "Failed to destroy mutex_eat\n");
    if (pthread_mutex_destroy(&(data->mutex_start)) != 0)
        fprintf(stderr, "Failed to destroy mutex_start\n");

    int i = 0;
    while (i < data->nbr_philo)
    {
        if (pthread_mutex_destroy(&(data->forks[i].fork)) != 0)
            fprintf(stderr, "Failed to destroy fork mutex %d\n", i);
        i++;
    }

    if (data->forks)
    {
        free(data->forks);
        data->forks = NULL; // Set pointer to NULL after freeing
    }
    if (data->philos)
    {
        free(data->philos);
        data->philos = NULL; // Set pointer to NULL after freeing
    }
}

void cleanup(t_data *data)
{
    if (!data)
        return;

    if (data->philos)
    {
        free(data->philos);
        data->philos = NULL;
    }

    if (data->forks)
    {
        free(data->forks);
        data->forks = NULL;
    }

    // Vérifiez que les mutex sont valides avant de les détruire
    if (&(data->mutex_print))
        pthread_mutex_destroy(&(data->mutex_print));
    if (&(data->mutex_eat))
        pthread_mutex_destroy(&(data->mutex_eat));
    if (&(data->mutex_start))
        pthread_mutex_destroy(&(data->mutex_start));
}
