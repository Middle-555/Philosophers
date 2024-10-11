/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 16:05:38 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 1. Parsing of error//
// 2. Data init//
// 3. Start the dinner
// 4. Free everything
// -> in case a philo die.
// -> in case all philo are full.
// Dans main.c, fonction main

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_arguments(argc, argv))
		return (1);
	if (!fill_input(&data, argv))
		error_msg("failed to fill input");
	if (!init_forks(&data))
	{
		cleanup(&data);
		error_msg("failed to init forks");
	}
	if (!init_philos(&data))
	{
		cleanup(&data);
		error_msg("failed to init philos");
	}
	test_fill_input(&data);
	test_forks(&data);
	test_philos(&data);
	//cleanup(&data);
	return (0);
}
