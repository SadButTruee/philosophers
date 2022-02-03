/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:45:55 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/22 15:30:30 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long int	ft_find_to_time(void)
{
	struct timeval	t;
	long long int	time;

	gettimeofday(&t, NULL);
	time = (t.tv_sec) * 1000 + (t.tv_usec) / 1000;
	return (time);
}

t_info	ft_find_to_info(t_ph *ph)
{
	long long int	time;

	time = ft_find_to_time();
	if (ph->last_eat == 0)
		ph->last_eat = ft_find_to_time() - 1;
	if (ph->spis->info == death)
		return (death);
	if (time - ph->last_eat > ph->spis->t_d)
	{
		ft_print_death(ph);
		return (death);
	}
	return (life);
}

void	ft_update_list(t_spis *spis, int ph)
{
	int	i;

	i = 0;
	while (i < spis->num_ph - 1)
	{
		spis->list[i] = spis->list[i + 1];
		i++;
	}
	spis->list[i] = ph;
}
