/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descendant_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:19:16 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 21:56:40 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_fork(t_ph *ph)
{
	sem_wait(ph->spis->fork);
	ft_print_info(ph, "has taken a fork");
	sem_wait(ph->spis->fork);
	ft_print_info(ph, "has taken a fork");
}

void	*ft_is_dead(void *ph1)
{
	t_ph	*ph;

	ph = ph1;
	while (1)
		ft_find_to_info(ph);
}

void	ft_eat(t_ph *ph)
{
	ft_print_info(ph, "is eating");
	ph->last_eat = ft_find_to_time();
	ph->num_eaten++;
	sem_post(ph->spis->sem_eat);
	ft_check_time_sleep_eat(ph->spis->t_e, ph);
	sem_post(ph->spis->fork);
	sem_post(ph->spis->fork);
}

void	*ft_descendant(void *ph1)
{
	t_ph		*ph;
	pthread_t	pth;

	ph = ph1;
	pthread_create(&pth, NULL, &ft_is_dead, ph);
	pthread_detach(pth);
	while (ph->spis->info == life)
	{
		if (ph->spis->num_ph != 1)
		{
			ft_fork(ph);
			ft_eat(ph);
			if (ph->spis->num_eat && ph->num_eaten == ph->spis->num_eat)
				break ;
			ft_print_info(ph, "is sleeping");
			ft_check_time_sleep_eat(ph->spis->t_s, ph);
			ft_print_info(ph, "is thinking");
		}
		ft_find_to_info(ph);
	}
	exit(EXIT_SUCCESS);
}
