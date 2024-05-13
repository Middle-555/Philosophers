/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:12:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/13 15:43:24 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc ==  5 || argc == 6)
	{
		// 1. Parsing of error
		// 2. Data init
		// 3. Start the dinner 
		// 4. Free everything 
			// -> in case a philo die.
			// -> in case all philo are full.
		printf("test");
	}
	else
		error_msg("Please use the correct prototype");
}
