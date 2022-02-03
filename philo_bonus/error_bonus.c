/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:59:47 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 19:26:26 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_error(int argc, char **argv)
{
	if (argc > 4 && argc < 7)
	{
		if (ft_atoi(argv[1]) < 1)
			ft_putstr("Error: the number_of_philosophers must be > 0\n");
		if (ft_atoi(argv[2]) < 1)
			ft_putstr("Error: the time to die must be > 0\n");
		if (ft_atoi(argv[3]) < 1)
			ft_putstr("Error: the time to eat must be > 0\n");
		if (ft_atoi(argv[4]) < 1)
			ft_putstr("Error: the time to sleep must be > 0\n");
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			ft_putstr("Error: the number_of_times_each_philosopher_must_eat \
				must be > 0\n");
	}
	else
		ft_putstr("Error: incorrect number of argument\n");
	return (0);
}
