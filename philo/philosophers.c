/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:18:30 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/20 17:43:22 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_ph	*ph;
	int		er;

	er = 0;
	if (argc > 4 && argc < 7)
	{
		if (ft_atoi(argv[1]) < 1)
			er = ft_putstr_ph("Error: the number_of_philosophers must be > 0\n");
		if (ft_atoi(argv[2]) < 1)
			er = ft_putstr_ph("Error: the time to die must be > 0\n");
		if (ft_atoi(argv[3]) < 1)
			er = ft_putstr_ph("Error: the time to eat must be > 0\n");
		if (ft_atoi(argv[4]) < 1)
			er = ft_putstr_ph("Error: the time to sleep must be > 0\n");
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			er = ft_putstr_ph("Error: the number_of_times_each_philosopher_must_eat \
				must be > 0\n");
	}
	else
		er = ft_putstr_ph("Error: incorrect number of argument\n");
	if (er)
		return (1);
	ph = ft_initialization_ph(argc, argv);
	ft_threads(ph);
	return (0);
}
