/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:46:45 by rtracee           #+#    #+#             */
/*   Updated: 2021/12/21 21:21:53 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum e_info
{
	life,
	death
}t_info;

typedef struct s_spis
{
	int				num_ph;
	int				t_d;
	int				t_e;
	int				t_s;
	int				num_eat;
	sem_t			*fork;
	sem_t			*death;
	sem_t			*outp;
	sem_t			*sem_eat;
	long long int	start;
	t_info			info;
}t_spis;

typedef struct s_ph
{
	int				id;
	pid_t			pid;
	t_spis			*spis;
	long long		last_eat;
	int				num_eaten;
}t_ph;

t_ph			*ft_initialization_ph(int argc, char **argv);
t_spis			*ft_initialization_spis(int argc, char **argv);

void			*ft_descendant(void *ph1);
void			ft_fork(t_ph *ph);

long long int	ft_find_to_time(void);
t_info			ft_find_to_info(t_ph *ph);
void			ft_check_time_sleep_eat(long long time, t_ph *ph);
void			*ft_is_dead(void *ph1);
void			*ft_all_eat(void *ph1);

void			ft_print_info(t_ph *ph, char *str);
void			ft_print_dead(t_ph *ph);

int				ft_error(int argc, char **argv);
void			ft_clear(t_ph *ph);
void			ft_kill(t_ph *ph);

int				ft_atoi(const char *str);
void			ft_putstr(char *s);
void			ft_putchar(char c);

#endif