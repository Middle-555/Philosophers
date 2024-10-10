/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:53:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/10 17:05:23 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// tiens dans un int et supérieur à 0;
// nombre valide;
// que des chiffres;
int	check_input(char *argv)
{
	if (!ft_isdigit_str(argv))
		error_msg("You need to put only numbers");
	return (1);
}

int	fill_input(t_data *data, char **argv)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->ttd = ft_atol(argv[2]);
	data->tte = ft_atol(argv[3]);
	data->tts = ft_atol(argv[4]);
	if (data->nbr_philo <= 0 || data->ttd <= 0
		|| data->tte <= 0 || data->tts <= 0)
	{
		printf("Error: Invalid input values\n");
		return (0);
	}
	if (argv[5])
	{
		data->meal_limit = ft_atol(argv[5]);
		if (data->meal_limit < 0)
		{
			printf("Error: Invalid meal limit\n");
			return (0);
		}
	}
	else
	{
		data->meal_limit = -1;
	}
	return (1);
}
