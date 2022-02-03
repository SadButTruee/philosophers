/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:42:13 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 18:16:57 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_print_dead(t_ph *ph)
{
	long long	time_in_ms;

	sem_wait(ph->spis->outp);
	time_in_ms = ft_find_to_time() - ph->spis->start;
	printf("%lld %d died\n", time_in_ms, ph->id);
	sem_post(ph->spis->death);
}

void	ft_print_info(t_ph *ph, char *str)
{
	long long	time_in_ms;

	sem_wait(ph->spis->outp);
	time_in_ms = ft_find_to_time() - ph->spis->start;
	if (ph->spis->info == life)
		printf("%lld %d %s\n", time_in_ms, ph->id, str);
	sem_post(ph->spis->outp);
}
