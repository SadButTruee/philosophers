/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:13:42 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 19:16:08 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_clear(t_ph *ph)
{
	sem_close(ph->spis->fork);
	sem_unlink("/ph_fork");
	sem_close(ph->spis->outp);
	sem_unlink("/ph_outp");
	sem_close(ph->spis->death);
	sem_unlink("/ph_death");
	sem_close(ph->spis->sem_eat);
	sem_unlink("/ph_eat");
	free(ph->spis);
	free(ph);
}
