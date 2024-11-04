/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 17:20:37 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_program(t_data *data, int argc, char **argv)
{
	if (!check_arguments(argc, argv))
		error_msg("wrong argument");
	if (!fill_input(data, argv))
	{
		cleanup(data);
		error_msg("failed to fill input");
	}
	if (!init_philos(data))
	{
		cleanup(data);
		error_msg("failed to init philos");
	}
	if (!init_forks(data))
	{
		cleanup(data);
		error_msg("failed to init forks");
	}
	if (!init_mutex(data))
	{
		cleanup(data);
		error_msg("failed to init mutex");
	}
	if (!create_threads(data))
	{
		cleanup(data);
		error_msg("failed to create threads");
	}
	monitor_routine(data);
}
