/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:35:58 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/22 13:55:09 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_death(t_ph *ph)
{
	long long	time;

	pthread_mutex_lock(&ph->spis->outp);
	time = ft_find_to_time() - ph->spis->start;
	if (ph->spis->info == life)
	{
		ph->spis->info = death;
		usleep(1000);
		printf("%lld %d died\n", time, ph->id);
	}
	pthread_mutex_unlock(&ph->spis->outp);
}

void	ft_print_info(t_ph *ph, char *str)
{
	long long	time_in_ms;

	pthread_mutex_lock(&ph->spis->outp);
	time_in_ms = ft_find_to_time() - ph->spis->start;
	if (ph->spis->info == life)
		printf("%lld %d %s\n", time_in_ms, ph->id, str);
	pthread_mutex_unlock(&ph->spis->outp);
}
