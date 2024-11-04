/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:50:09 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 17:20:35 by kpourcel         ###   ########.fr       */
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
			data->philos[i].right_fork->fork_id,
			data->philos[i].left_fork->fork_id);
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

/*
void test_philosopher_locks_forks_correct_order(void) 
{
    t_data data;
    t_philo philo;
    t_fork forks[2];
    
    // Initialize data and philosopher
    data.forks = forks;
    philo.data = &data;
    philo.left_fork = &forks[0];
    philo.right_fork = &forks[1];
    forks[0].fork_id = 0;
    forks[1].fork_id = 1;
    
    // Initialize mutexes
    pthread_mutex_init(&(forks[0].fork), NULL);
    pthread_mutex_init(&(forks[1].fork), NULL);
    pthread_mutex_init(&(data.mutex_eat), NULL);
    
    // Call the function
    eat_philosopher(&philo);
    
    // Check if the philosopher has eaten
    assert(philo.meals == 1);
    
    // Destroy mutexes
    pthread_mutex_destroy(&(forks[0].fork));
    pthread_mutex_destroy(&(forks[1].fork));
    pthread_mutex_destroy(&(data.mutex_eat));
}
*/
    // Both forks are already locked by another philosopher
void test_philosopher_forks_already_locked(void)
{
    t_data data;
    t_philo philo;
    t_fork forks[2];
    
    // Initialize data and philosopher
    data.forks = forks;
    philo.data = &data;
    philo.left_fork = &forks[0];
    philo.right_fork = &forks[1];
    forks[0].fork_id = 0;
    forks[1].fork_id = 1;
    
    // Initialize mutexes and lock them to simulate another philosopher holding them
    pthread_mutex_init(&(forks[0].fork), NULL);
    pthread_mutex_init(&(forks[1].fork), NULL);
    pthread_mutex_lock(&(forks[0].fork));
    pthread_mutex_lock(&(forks[1].fork));
    
    // Call the function in a separate thread to avoid deadlock in the test
    pthread_t thread;
    pthread_create(&thread, NULL, (void *(*)(void *))eat_philosopher, &philo);
    
    // Wait for a short time to simulate the philosopher trying to eat
    sleep(1);
    
    // Check if the philosopher has not eaten
    assert(philo.meals == 0);
    
    // Unlock the forks and destroy mutexes
    pthread_mutex_unlock(&(forks[0].fork));
    pthread_mutex_unlock(&(forks[1].fork));
    pthread_mutex_destroy(&(forks[0].fork));
    pthread_mutex_destroy(&(forks[1].fork));
}
