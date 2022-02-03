/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:42:21 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/20 17:42:37 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_clear(pthread_t	*pth, t_ph *ph)
{
	free(pth);
	free(ph->spis->fork);
	free(ph->spis->list);
	free(ph->spis);
	free(ph);
}
