/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:00:24 by kpourcel          #+#    #+#             */
/*   Updated: 2024/09/30 17:09:16 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*safe_malloc(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
		error_msg("Malloc error");
	return (dst);
}
