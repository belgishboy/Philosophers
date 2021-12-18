/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:41:33 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/18 20:42:08 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Contains the main routine functions for the threads
*/

#include "../philo.h"

/*
**Main routine function
** timestamp when you eaten, # of times eaten
*/

void	*routine(void *v)
{
	t_philo	p;
	int		n;

	p = *(t_philo *)v;
	n = (p.p_n + 1) % p.t->nphilo;
	while (p.al && p.t->al)
	{
		if (!p.al || get_time() - p.t_e >= p.t->t2d)
		{
			p.t->al = 0;
			p.al = 0;
			prt_status(&p, p.t, 5, get_time());
			return (NULL);
		}
		prt_status(&p, p.t, 4, get_time());
		if (!p.al || get_time() - p.t_e >= p.t->t2d)
		{
			p.t->al = 0;
			p.al = 0;
			prt_status(&p, p.t, 5, get_time());
			return (NULL);
		}
		pthread_mutex_lock(&p.t->f[p.p_n]);
		if (!p.al || get_time() - p.t_e >= p.t->t2d)
		{
			p.t->al = 0;
			p.al = 0;
			prt_status(&p, p.t, 5, get_time());
			return (NULL);
		}
		prt_status(&p, p.t, 1, get_time());
		if (!p.al || get_time() - p.t_e >= p.t->t2d)
		{
			p.t->al = 0;
			p.al = 0;
			prt_status(&p, p.t, 5, get_time());
			return (NULL);
		}
		pthread_mutex_lock(&p.t->f[n]);
		if (!p.al || get_time() - p.t_e >= p.t->t2d)
		{
			p.t->al = 0;
			p.al = 0;
			prt_status(&p, p.t, 5, get_time());
			return (NULL);
		}
		prt_status(&p, p.t, 1, get_time());
		if (!p.al || get_time() - p.t_e >= p.t->t2d)
		{
			p.t->al = 0;
			p.al = 0;
			prt_status(&p, p.t, 5, get_time());
			return (NULL);
		}
		prt_status(&p, p.t, 2, get_time());
		p.n_e ++;
		p.t_e = get_time();
		if (p.n_e == p.t->stomach)
			p.t->d_e ++;
		usleep(p.t->t2e);
		pthread_mutex_unlock(&p.t->f[n]);
		pthread_mutex_unlock(&p.t->f[p.p_n]);
		prt_status(&p, p.t, 3, get_time());
		usleep(p.t->t2s);
		if (p.n_e == 12)
		{
			printf("philo %d had eaten 12 times\n", p.p_n);
			p.t->al = 0;
		}
	}
	p.t->al = 0;
	return (NULL);
}

/*
** test routine

void	*troutine(void *v)
{
	int		x;
	t_philo	*p;

	printf("started\n");
	p = (t_philo *)v;
	x = 0;
	while (p->al && x < 3)
	{
		printf("Thread %d says hi\n", p->p_n);
		x ++;
	}
	return (NULL);
}
*/