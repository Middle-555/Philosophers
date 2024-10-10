/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/10 17:13:31 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;
/**
 * @brief
 *
 */

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					philo_id;
	long				meals;
	long				time_since_meal;
	t_fork				*left_fork;
	t_fork				*right_fork;
	bool				full;
	pthread_t			thread_id;
	t_data				*data;
}						t_philo;

//TTS = Time to sleep, TTE =  Time to Eat, TTD = Time to Die
typedef struct s_data
{
	t_fork				*forks;
	t_philo				*philos;
	long				tts;
	long				tte;
	long				ttd;
	long				meal_limit;
	long				nbr_philo;
	pthread_t			monitor_thread;
	long				start;
	bool				end;
}						t_data;

// checking_error.c
int		check_input(char *argv);
int		fill_input(t_data *data, char **argv);

// data.c 

int		init_data(t_data *data);
int		init_philo(t_data *data);
void	fork_assignement(t_philo *philo, t_data *data, int id);

// philo_routine.c
int		take_forks(t_philo *philo);
void	philo_sleep_and_think(t_philo *philo);
void	philo_eat(t_philo *philo);

// philo.c 
void	*philo_routine(void *arg);
void	*monitor_philosophers(void *arg);
int		start_dinner(t_data *data);
int		initialize_program(t_data *data, int argc, char **argv);
int		take_forks(t_philo *philo);
void	release_forks(t_philo *philo);
// utils.c 
void	error_msg(char *str);
int		ft_isdigit(int c);
int		ft_isdigit_str(char *str);
int		ft_isspace(char c);
long	ft_atol(const char *str);

// utils2.c
void	*safe_malloc(size_t size);
void		cleanup(t_data *data);
long long		get_time(void);

// tester.c
void	test_forks(t_data *data);
void	test_philos(t_data *data);

#endif