/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 16:14:54 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_program(t_data *data, int argc, char **argv)
{
	if (!check_arguments(argc, argv))
		error_msg("wrong argument");
	if (!fill_input(data, argv))
		error_msg("failed to fill input");
	if (!init_forks(data))
	{
		cleanup(data);
		error_msg("failed to init forks");
	}
	if (!init_philos(data))
	{
		cleanup(data);
		error_msg("failed to init philos");
	}
}
