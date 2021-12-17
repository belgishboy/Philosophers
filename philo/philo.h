/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:34:49 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/17 17:07:14 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Philosopher
*/

#ifndef PHILO_H
# define PHILO_H

/*
**INCLUDES
*/

# include <unistd.h> // write, usleep
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <string.h> // memset
# include <sys/time.h> // gettimeofday
# include <pthread.h>

/*
**Table structure
** nphilo == # of philosophers; t2d == time to die;	t2e == time to eat;
** t2s == time to sleep;	stomach == # times they must eat; al == alive;
** st == start timestamp;	ct == current timestamp;
** f == mutex fork array;	a_t == thread array;
** a_p == philosphers struct array;
*/

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				nphilo;
	int				t2d;
	int				t2e;
	int				t2s;
	int				stomach;
	int				d_e;
	int				al;
	long long		st;
	long long		ct; // has to be local to each routine
	struct timeval	*time;
	pthread_mutex_t	*f;
	pthread_mutex_t	prt;
	pthread_t		*a_t;
	t_philo			*a_p;
}	t_table;

/*
**Philosophers structure
**n_e == number of times eaten; al == if alive; p_n == philo #;
**t_e == timestamp of when eaten; t == pointer to table
*/

typedef struct s_philo
{
	int			p_n;
	int			n_e;
	int			al;
	long long	t_e;
	t_table		*t; // pointer??
}	t_philo;

/*
**Utility functions
*/

int			ft_atoi(const char *nptr);
long long	get_time(void);
size_t		ft_strlen(const char *s);
int			ft_argvemptycheck(char **argv);
int			ft_argvdigitcheck(char **argv);
void		prt_status(t_philo *phil, t_table *t, int status);

/*
**Functions
*/

int			set_table(int argc, char **argv, t_table *t);
void		*routine(void *v);

#endif