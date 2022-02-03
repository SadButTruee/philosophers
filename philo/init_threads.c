/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:05:15 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/23 15:23:16 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_is_dead(void *ph1)
{
	t_ph	*ph;

	ph = ph1;
	while (1)
	{
		ft_find_to_info(ph);
		usleep(5000);
	}
}

void	ft_game(t_ph *ph)
{
	while (ph->spis->info == life)
	{
		ft_find_to_info(ph);
		if (ph->id != ph->spis->list[0])
			continue ;
		if (ph->spis->num_ph != 1)
		{
			ft_process_fork(ph);
			ft_process_eating(ph);
			if (ph->spis->num_eat && ph->num_eaten == ph->spis->num_eat)
				break ;
			ft_print_info(ph, "is sleeping");
			ft_check_time_sleep_eat(ph->spis->t_s, ph);
			ft_print_info(ph, "is thinking");
		}
		else
		{
			ft_fork1(ph);
			break ;
		}
		ft_find_to_info(ph);
	}
}

void	*ft_init_threads_ph(void *ph1)
{
	t_ph		*ph;
	pthread_t	pth;

	ph = ph1;
	pthread_create(&pth, NULL, &ft_is_dead, ph);
	pthread_detach(pth);
	ft_game(ph);
	return (0);
}
