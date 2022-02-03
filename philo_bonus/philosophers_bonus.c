/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:45:27 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 21:23:05 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_kill(t_ph *ph)
{
	int	i;

	i = 0;
	while (i < ph->spis->num_ph)
	{
		kill(ph[i].pid, SIGKILL);
		i++;
	}
}

void	ft_game(int argc, char **argv)
{
	t_ph		*ph;
	pthread_t	pth;
	int			i;

	i = 0;
	ph = ft_initialization_ph(argc, argv);
	if (argv[5])
		pthread_create(&pth, NULL, ft_all_eat, ph);
	while (i < ph->spis->num_ph)
	{
		ph[i].pid = fork();
		if (ph[i].pid == 0)
			ft_descendant(&(ph[i]));
		i++;
	}
	sem_wait(ph->spis->death);
	ph->spis->info = death;
	sem_post(ph->spis->sem_eat);
	if (argv[5])
		pthread_join(pth, NULL);
	ft_clear(ph);
}

int	main(int argc, char **argv)
{
	if (ft_error(argc, argv) != 0)
		return (1);
	ft_game(argc, argv);
	return (0);
}
