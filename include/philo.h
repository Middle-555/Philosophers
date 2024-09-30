/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/09/30 16:36:55 by kpourcel         ###   ########.fr       */
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
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					philo_id;
	long				meals_needed;
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
	long				start;
	bool				end;
}						t_data;

// checking_error.c
int		check_input(char *argv);
void	fill_input(t_data *data, char **argv);
// philo.c 

void	init_data(t_data *data);
// utils.c 
void	error_msg(char *str);
int		ft_isdigit(int c);
int		ft_isdigit_str(char *str);
int		ft_isspace(char c);
long	ft_atol(const char *str);

#endif