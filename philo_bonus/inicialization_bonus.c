/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:10:28 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/22 15:57:57 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_spis	*ft_initialization_spis(int argc, char **argv)
{
	t_spis	*spis;

	spis = malloc(sizeof(t_spis));
	spis->num_ph = ft_atoi(argv[1]);
	spis->t_d = ft_atoi(argv[2]);
	spis->t_e = ft_atoi(argv[3]);
	spis->t_s = ft_atoi(argv[4]);
	spis->start = ft_find_to_time();
	spis->info = life;
	sem_unlink("/ph_fork");
	sem_unlink("/ph_death");
	sem_unlink("/ph_outp");
	sem_unlink("/ph_eat");
	spis->fork = sem_open("/ph_fork", O_CREAT, 0700, spis->num_ph);
	spis->death = sem_open("/ph_death", O_CREAT, 0700, 0);
	spis->outp = sem_open("/ph_outp", O_CREAT, 0700, 1);
	spis->sem_eat = sem_open("/ph_eat", O_CREAT, 0700, 0);
	if (argc == 6)
		spis->num_eat = ft_atoi(argv[5]);
	else
		spis->num_eat = 0;
	return (spis);
}

t_ph	*ft_initialization_ph(int argc, char **argv)
{
	t_spis	*spis;
	t_ph	*ph;
	int		i;

	i = 0;
	spis = ft_initialization_spis(argc, argv);
	ph = malloc(spis->num_ph * sizeof(t_spis));
	while (i < spis->num_ph)
	{
		ph[i].id = i + 1;
		ph[i].spis = spis;
		ph[i].last_eat = 0;
		ph[i].num_eaten = 0;
		i++;
	}
	return (ph);
}
