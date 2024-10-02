/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/02 15:09:43 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 1. Parsing of error//
// 2. Data init//
// 3. Start the dinner
// 4. Free everything
// -> in case a philo die.
// -> in case all philo are full.
int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc == 5 || argc == 6)
	{
		i = 1;
		while (i < argc)
		{
			if (!check_input(argv[i]))
				return (1);
			i++;
		}
		fill_input(&data, argv);
		init_data(&data);
		init_philo(&data);
		//start_routine;
	}
	else
		error_msg("Please use the correct prototype.");
	return (0);
}
