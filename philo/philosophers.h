/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:18:47 by rtracee           #+#    #+#             */
/*   Updated: 2022/01/18 12:18:14 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
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
	pthread_mutex_t	*fork;
	pthread_mutex_t	outp;
	long long int	start;
	t_info			info;
	int				*list;
}t_spis;

typedef struct s_ph
{
	int				id;
	t_spis			*spis;
	long long int	last_eat;
	int				num_eaten;
}t_ph;

int				ft_threads(t_ph *ph);
void			ft_game(t_ph *ph);

t_ph			*ft_initialization_ph(int argc, char **argv);
t_spis			*ft_initialization_spis(int argc, char **argv);
pthread_mutex_t	*ft_initialization_fork(t_spis *spis);
int				*ft_initialization_list(t_spis *spis);

void			ft_process_fork(t_ph *ph);
void			ft_fork1(t_ph *ph);
void			ft_process_eating(t_ph *ph);
void			ft_check_time_sleep_eat(long long time, t_ph *ph);

void			*ft_init_threads_ph(void *ph1);
void			*ft_is_dead(void *ph1);
void			ft_update_list(t_spis *spis, int ph);

long long int	ft_find_to_time(void);
t_info			ft_find_to_info(t_ph *ph);

void			ft_print_death(t_ph *ph);
void			ft_print_info(t_ph *ph, char *str);

void			ft_clear(pthread_t	*pth, t_ph *ph);

int				ft_atoi(const char *str);
int				ft_putstr_ph(char *s);
void			ft_putchar(char c);
#endif
