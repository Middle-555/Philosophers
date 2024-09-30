/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:53:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/09/30 16:58:10 by kpourcel         ###   ########.fr       */
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

void	fill_input(t_data *data, char **argv)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->ttd = ft_atol(argv[2]) * 1000;
	data->tte = ft_atol(argv[3]) * 1000;
	data->tts = ft_atol(argv[4]) * 1000;
	if (argv[5])
		data->meal_limit = ft_atol(argv[5]);
	else
		data->meal_limit = -1;
}
