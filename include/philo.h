/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/13 15:44:42 by kpourcel         ###   ########.fr       */
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

typedef struct s_data
{
	t_fork				*forks;
	t_philo				*philos;
	long				time_to_sleep;
	long				time_to_eat;
	long				time_to_die;
	long				meal_limit;
	long				nbr_philo;
	long				start;
	bool				end;
}						t_data;

// philo.c 

// utils.c 
void	error_msg(char *str);
#endif