/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:04:39 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/16 20:50:33 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
/*
**Contains all the actions the philopher can take
*/

int	ph_eat(t_philo *p)
{
	long long	c_t;

	pthread_mutex_lock(&p->t->prt);
	if (p->t->al == 0 || p->al == 0)
	{
		pthread_mutex_unlock(&p->t->prt);
		return (1);
	}
	c_t = get_time() - p->t->st;
	printf("%lld %d is eating\n", c_t, p->p_n + 1);
	p->t_e = get_time();
	p->n_e ++;
	if (p->n_e == p->t->stomach)
		p->t->d_e ++;
	pthread_mutex_unlock(&p->t->prt);
	ft_usleep(p->t, p->t->t2e);
	return (0);
}

int	ph_fork(t_philo *p)
{
	long long	c_t;

	pthread_mutex_lock(&p->t->prt);
	if (p->t->al == 0 || p->al == 0)
	{
		pthread_mutex_unlock(&p->t->prt);
		return (1);
	}
	c_t = get_time() - p->t->st;
	printf("%lld %d has taken a fork\n", c_t, p->p_n + 1);
	pthread_mutex_unlock(&p->t->prt);
	return (0);
}

int	ph_sleep(t_philo *p)
{
	long long	c_t;

	pthread_mutex_lock(&p->t->prt);
	if (p->t->al == 0 || p->al == 0)
	{
		pthread_mutex_unlock(&p->t->prt);
		return (1);
	}
	c_t = get_time() - p->t->st;
	printf("%lld %d is sleeping\n", c_t, p->p_n + 1);
	pthread_mutex_unlock(&p->t->prt);
	ft_usleep(p->t, p->t->t2s);
	ph_think(p);
	return (0);
}

int	ph_think(t_philo *p)
{
	long long	c_t;

	pthread_mutex_lock(&p->t->prt);
	if (p->t->al == 0 || p->al == 0)
	{
		pthread_mutex_unlock(&p->t->prt);
		return (1);
	}
	c_t = get_time() - p->t->st;
	printf("%lld %d is thinking\n", c_t, p->p_n + 1);
	pthread_mutex_unlock(&p->t->prt);
	return (0);
}

void	ft_usleep(t_table *t, long long time_limit)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time_limit / 1000)
	{
		if (t->nphilo < 100)
			usleep(100);
		else
			usleep(1000);
	}
}
