/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:41:35 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/20 17:42:09 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_threads(t_ph *ph)
{
	pthread_t	*pth;
	int			i;

	i = -1;
	pth = malloc(sizeof(pthread_t) * ph->spis->num_ph);
	while (++i < ph->spis->num_ph)
		pthread_create(&pth[i], NULL, ft_init_threads_ph, &ph[i]);
	i = 0;
	while (i < ph->spis->num_ph)
		pthread_join(pth[i++], NULL);
	ft_clear(pth, ph);
	return (0);
}
