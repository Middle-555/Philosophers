/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:13 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 18:12:11 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philosopher_routine(void *arg)
{
    t_philo	*philo;
    t_data	*data;

    philo = (t_philo *)arg;
    data = philo->data;

    pthread_mutex_lock(&(data->mutex_start));
    data->start = get_time();
    pthread_mutex_unlock(&(data->mutex_start));

    if (philo->philo_id % 2 == 0)
        usleep(500);

    while (1)
    {
        pthread_mutex_lock(&(data->mutex_eat));
        if (data->is_dead || data->end)
        {
            printf("Philosophe %d quitte la boucle : is_dead=%d, end=%d\n",
                   philo->philo_id, data->is_dead, data->end);
            pthread_mutex_unlock(&(data->mutex_eat));
            break;
        }
        pthread_mutex_unlock(&(data->mutex_eat));

        // Philosophe mange
        eat_philosopher(philo);
       // printf("Philosophe %d a mis à jour time_since_meal à %lld ms\n",
              // philo->philo_id, (long long)philo->time_since_meal);

        // Philosophe dort
        print_status(data, philo->philo_id, "is sleeping");
        sleep_time(data->tts, data);

        // Philosophe pense
        print_status(data, philo->philo_id, "is thinking");
    }
    return (NULL);
}


void	eat_philosopher(t_philo *philo)
{
	t_data	*data;

	data = philo->data;

	// Prise des fourchettes dans un ordre défini pour éviter les deadlocks
	if (philo->left_fork->fork_id < philo->right_fork->fork_id)
	{
		pthread_mutex_lock(&(data->forks[philo->right_fork - data->forks].fork));
		print_status(data, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&(data->forks[philo->left_fork - data->forks].fork));
	}
	else
	{
		pthread_mutex_lock(&(data->forks[philo->left_fork - data->forks].fork));
		print_status(data, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&(data->forks[philo->right_fork - data->forks].fork));
	}
	print_status(data, philo->philo_id, "has taken a fork");

	// Philosophe mange maintenant qu'il a deux fourchettes
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "is eating");
	philo->time_since_meal = get_time(); // Mise à jour du temps du dernier repas
	(philo->meals)++;
	pthread_mutex_unlock(&(data->mutex_eat));

	// Philosophe mange pour une durée `tte`
	sleep_time(data->tte, data);

	// Libération des fourchettes dans l'ordre inverse
	pthread_mutex_unlock(&(data->forks[philo->right_fork - data->forks].fork));
	pthread_mutex_unlock(&(data->forks[philo->left_fork - data->forks].fork));
}

void	sleep_time(long long time, t_data *data)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		pthread_mutex_lock(&(data->mutex_eat));
		if (data->is_dead || data->end)
		{
			pthread_mutex_unlock(&(data->mutex_eat));
			break;
		}
		pthread_mutex_unlock(&(data->mutex_eat));
		usleep(50); // Pause courte pour éviter de surcharger le CPU
	}
}


int	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
		{
			error_msg("Failed to join thread");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_meal_count(t_data *data)
{
	int	i;
	int	all_done;

	i = 0;
	all_done = 1;
	pthread_mutex_lock(&(data->mutex_eat));
	while (i < data->nbr_philo)
	{
		if (data->philos[i].meals < data->meal_limit)
		{
			all_done = 0; // Un philosophe n'a pas encore atteint la limite
			break;
		}
		i++;
	}
	if (all_done)
		data->end = 1; // Tous les philosophes ont mangé suffisamment
	pthread_mutex_unlock(&(data->mutex_eat));
	return (all_done);
}

