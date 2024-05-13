/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/13 14:10:21 by kpourcel         ###   ########.fr       */
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

/**
 * @brief 
 * 
 */

typedef struct s_data
{
	int					philo_id;
	long				meals_needed;
	long				time_since_meal;
	t_fork				*left_fork;
	t_fork				*right_fork;
	bool				full;
}						t_data;

/**
 * @brief 
 * 
 */

typedef pthread_mutex_t	t_mtx;
/**
 * @brief 
 * 
 */

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

#endif