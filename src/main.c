/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/04 14:47:18 by kpourcel         ###   ########.fr       */
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

	monitor_philos(&data, argc, argv);
	//init_program(&data, argc, argv);
	test_fill_input(&data);
	test_forks(&data);
	test_philos(&data);
	//test_philosopher_forks_already_locked();
	//test_philosopher_locks_forks_correct_order();
	//monitor_philos(&data);
	return (0);
}
