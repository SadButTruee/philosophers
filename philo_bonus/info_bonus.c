/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:47:50 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/22 12:54:42 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
		ft_print_dead(ph);
		return (death);
	}
	return (life);
}

void	*ft_all_eat(void *ph1)
{
	t_ph	*ph;
	int		i;

	ph = ph1;
	i = 0;
	while (i < ph->spis->num_eat * ph->spis->num_ph)
	{
		sem_wait(ph->spis->sem_eat);
		if (ph->spis->info == death)
			return (NULL);
		i++;
	}
	sem_post(ph->spis->death);
	return (0);
}

void	ft_check_time_sleep_eat(long long time, t_ph *ph)
{
	long long	time_in_ms;

	time_in_ms = ft_find_to_time();
	ft_find_to_info(ph);
	while (ph->spis->info == life)
	{
		if (ft_find_to_time() - time_in_ms > ph->spis->t_d - 1)
			ft_print_dead(ph);
		if (ft_find_to_time() - time_in_ms >= time)
			break ;
		usleep(50);
	}
}
