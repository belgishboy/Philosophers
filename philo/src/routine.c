/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:41:33 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/16 20:52:19 by vheymans         ###   ########.fr       */
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
	t_philo	*p;

	p = (t_philo *)v;
	while (1)
	{
		pthread_mutex_lock(&p->t->prt);
		if (!p->t->al)
			pthread_mutex_unlock(&p->t->prt);
		if (!p->t->al)
			return (NULL);
		pthread_mutex_unlock(&p->t->prt);
		pthread_mutex_lock(&p->t->f[p->p_n]);
		ph_fork(p);
		if (p->p_n == (p->p_n + 1) % p->t->nphilo)
			pthread_mutex_unlock(&p->t->f[p->p_n]);
		if (p->p_n == (p->p_n + 1) % p->t->nphilo)
			break ;
		pthread_mutex_lock(&p->t->f[(p->p_n + 1) % p->t->nphilo]);
		ph_fork(p);
		ph_eat(p);
		pthread_mutex_unlock(&p->t->f[(p->p_n + 1) % p->t->nphilo]);
		pthread_mutex_unlock(&p->t->f[p->p_n]);
		ph_sleep(p);
	}
	return (NULL);
}
