/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:53:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/11 15:29:18 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// tiens dans un int et supérieur à 0;
// nombre valide;
// que des chiffres;
int	check_input(char *argv)
{
	if (!ft_isdigit_str(argv))
		error_msg("You need to put only  positiv numbers");
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int		i;
	long	value;

	if (argc < 5 || argc > 6)
	{
		error_msg("Incorrect number of arguments.");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (value <= 0)
		{
			error_msg("Arguments must be greater than 0.");
			return (0);
		}
		i++;
	}
	return (1);
}
