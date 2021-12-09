/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:41:33 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/09 21:02:41 by vheymans         ###   ########.fr       */
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

	p = *(t_philo *)v;
	while (p.al)
	{
		pthread_mutex_lock(&p.t->f[p.p_n]);
	}
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
