/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:41:33 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/10 18:46:59 by vheymans         ###   ########.fr       */
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
	int x = 0;

	p = *(t_philo *)v;
	n = (p.p_n + 1) % p.t->nphilo;
	while (p.al)
	{
		//if (!(pthread_mutex_lock(&p.t->f[p.p_n])) && !(pthread_mutex_lock(&p.t->f[n])))
		//{
			pthread_mutex_lock(&p.t->f[p.p_n]);
			//printf("fork %d is locked by philo %d\n", p.p_n, p.p_n);
			pthread_mutex_lock(&p.t->f[n]);
			//printf("fork %d is locked by philo %d\n", n, p.p_n);
			printf("Philo %d is eating\n", p.p_n);
			usleep(p.t->t2e);
			pthread_mutex_unlock(&p.t->f[p.p_n]);
			//printf("fork %d is unlocked by philo %d\n", p.p_n, p.p_n);
			pthread_mutex_unlock(&p.t->f[n]);
			//printf("fork %d is unlocked by philo %d\n", n, p.p_n);
		//}
		printf("Philo %d is sleeping\n", p.p_n);
		usleep(p.t->t2s);
		x ++;
		if (x == 2)
			p.al = 0;
	}
	p.t->al = 0;
	return (NULL);
}

/*
** test routine
*/

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
