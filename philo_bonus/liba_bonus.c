/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:57:11 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 19:30:28 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	s;
	int	z;

	n = 0;
	z = 1;
	s = 0;
	while ((str [s] == ' ') || (str[s] >= 9 && str[s] <= 13))
		s++;
	if (str[s] == '-' || str[s] == '+')
	{
		if (str[s] == '-')
			z = -z;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		n = n * 10 + (str[s] - 48);
		s++;
	}
	return (n * z);
}

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
