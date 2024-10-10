/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/10 15:40:14 by kpourcel         ###   ########.fr       */
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

	if (!initialize_program(&data, argc, argv))
	{
		printf("Error: Failed to initialize the program\n");
		return (1);
	}
	if (!start_dinner(&data))
	{
		printf("Error: Failed to start dinner\n");
		return (1);
	}
	cleanup(&data);
	return (0);
}
