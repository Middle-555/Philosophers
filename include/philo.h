/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 14:46:44 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <assert.h>
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
 * @brief Structure représentant une fourchette.
 */
typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

/**
 * @brief Structure représentant un philosophe.
 */
typedef struct s_philo
{
	int					philo_id;
	long				meals;
	long				time_since_meal;
	t_fork				*left_fork;
	t_fork				*right_fork;
	int				full;
	pthread_t			thread_id;
	t_data				*data;
}						t_philo;

/**
 * @brief Structure contenant les données globales.
 *
 * TTS = Time to sleep, TTE = Time to eat, TTD = Time to die.
 */
typedef struct s_data
{
	t_fork				*forks;
	t_philo				*philos;
	int					check_eat;
	int					is_dead;
	long				tts;
	long				tte;
	long				ttd;
	long				meal_limit;
	long				nbr_philo;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_eat;
	pthread_mutex_t		mutex_start;
	long				start;
	bool				end;
}						t_data;

// checking_error.c
int			check_input(char *argv);
int			check_arguments(int argc, char **argv);

// data.c
int			init_forks(t_data *data);
int			init_philos(t_data *data);
int			fill_input(t_data *data, char **argv);
int			create_threads(t_data *data);
int			init_mutex(t_data *data);

// free_data.c
void		end_simulation(t_data *data);
void		cleanup(t_data *data);
// philo_routine.c
void		*philosopher_routine(void *arg);
void		eat_philosopher(t_philo *philo);
void		sleep_time(long long time, t_data *data);
int			wait_for_threads(t_data *data);
int			check_meal_count(t_data *data);

// philo_death.c
void		check_death(t_data *data);
void		monitor_philos(t_data *data, int argc, char **argv);
// philo.c
void		init_program(t_data *data, int argc, char **argv);

// utils.c
void		error_msg(char *str);
int			ft_isdigit(int c);
int			ft_isdigit_str(char *str);
int			ft_isspace(char c);
long		ft_atol(const char *str);

// utils2.c
long long	get_time(void);
void		*safe_malloc(size_t size);
void		cleanup(t_data *data);
void		one_philo_case(long ttd);
void		print_status(t_data *data, int philo_id, char *msg);

// tester.c
void		test_forks(t_data *data);
void		test_philos(t_data *data);
void		test_fill_input(t_data *data);
void		test_philosopher_forks_already_locked(void);
void 		test_philosopher_locks_forks_correct_order(void);
#endif
