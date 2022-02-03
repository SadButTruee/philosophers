/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:30:51 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/23 15:21:37 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_time_sleep_eat(long long time, t_ph *ph)
{
	long long	time_in_ms;

	time_in_ms = ft_find_to_time();
	ft_find_to_info(ph);
	while (ph->spis->info == life)
	{
		if (ft_find_to_time() - time_in_ms >= ph->spis->t_d)
			ft_print_death(ph);
		if (ft_find_to_time() - time_in_ms >= time)
			break ;
		usleep(900);
	}
}

void	ft_fork1(t_ph *ph)
{
	pthread_mutex_lock(&ph->spis->fork[0]);
	ft_print_info(ph, "has taken a fork");
	printf("%d %d %s\n", 801, ph->id, "is dead");
	pthread_mutex_unlock(&ph->spis->fork[0]);
}

void	ft_process_fork(t_ph *ph)
{
	pthread_mutex_lock(&ph->spis->fork[ph->id - 1]);
	ft_print_info(ph, "has taken a fork");
	if (ph->id == ph->spis->num_ph)
		pthread_mutex_lock(&ph->spis->fork[0]);
	else
		pthread_mutex_lock(&ph->spis->fork[ph->id]);
	ft_print_info(ph, "has taken a fork");
	ft_update_list(ph->spis, ph->id);
}

void	ft_process_eating(t_ph *ph)
{
	ft_print_info(ph, "is eating");
	ph->last_eat = ft_find_to_time();
	ph->num_eaten++;
	ft_check_time_sleep_eat(ph->spis->t_e, ph);
	pthread_mutex_unlock(&ph->spis->fork[ph->id - 1]);
	if (ph->id == ph->spis->num_ph)
		pthread_mutex_unlock(&ph->spis->fork[0]);
	else
		pthread_mutex_unlock(&ph->spis->fork[ph->id]);
}
