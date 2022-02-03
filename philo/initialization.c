/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:51:33 by rtracee           #+#    #+#             */
/*   Updated: 2022/01/18 12:18:00 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	*ft_initialization_list(t_spis *spis)
{
	int	*list;
	int	i;
	int	id;

	i = 0;
	id = 1;
	list = malloc(sizeof(int) * spis->num_ph);
	while (id <= spis->num_ph)
	{
		list[i] = id;
		i++;
		id += 2;
	}
	id = 2;
	while (id <= spis->num_ph)
	{
		list[i] = id;
		i++;
		id += 2;
	}
	return (list);
}

pthread_mutex_t	*ft_initialization_fork(t_spis *spis)
{
	pthread_mutex_t	*f;
	int				i;

	i = 0;
	f = malloc(spis->num_ph * sizeof(pthread_mutex_t));
	while (i < spis->num_ph)
	{
		pthread_mutex_init(&f[i], NULL);
		i++;
	}
	return (f);
}

t_spis	*ft_initialization_spis(int argc, char **argv)
{
	t_spis	*spis;

	spis = malloc(sizeof(t_spis));
	spis->num_ph = ft_atoi(argv[1]);
	spis->t_d = ft_atoi(argv[2]);
	spis->t_e = ft_atoi(argv[3]);
	spis->t_s = ft_atoi(argv[4]);
	spis->start = ft_find_to_time();
	spis->fork = ft_initialization_fork(spis);
	spis->info = life;
	spis->list = ft_initialization_list(spis);
	pthread_mutex_init(&spis->outp, NULL);
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
	ph = malloc(sizeof(t_ph) * spis->num_ph);
	{
		while (i < spis->num_ph)
		{
			ph[i].id = i + 1;
			ph[i].spis = spis;
			ph[i].last_eat = 0;
			ph[i].num_eaten = 0;
			i++;
		}
	}
	return (ph);
}
