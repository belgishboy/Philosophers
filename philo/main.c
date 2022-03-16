/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:56:01 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/16 20:53:37 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meal(t_table *t)
{
	int	x;
	int	i;

	t->st = get_time();
	x = 0;
	i = 0;
	while (i++ < 2)
	{
		while (x < t->nphilo)
		{
			t->a_p[x].t_e = t->st;
			t->a_p[x].p_n = x;
			if (pthread_create(&t->a_t[x], NULL, &routine, &t->a_p[x]))
				return (printf("Thread Error\n"));
			x += 2;
		}
		x = 1;
		usleep(100);
	}
	check(t);
	return (0);
}

int	check(t_table *t)
{
	int		x;
	t_philo	*p;

	while (t->al)
	{
		pthread_mutex_lock(&t->prt);
		x = 0;
		while (x < t->nphilo)
		{
			p = &t->a_p[x];
			if (get_time() - p->t_e >= t->t2d)
			{
				t->al = 0;
				printf("%lld %d is dead\n", get_time() - t->st, x + 1);
				pthread_mutex_unlock(&t->prt);
				return (0);
			}
			x ++;
		}
		if (t->d_e >= t->nphilo)
			t->al = 0;
		pthread_mutex_unlock(&t->prt);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	t;
	int		x;

	if (!(argc == 5 || argc == 6))
		return (printf("Number of arguments is incorrect\nError\n"));
	if (set_table(argc, argv, &t))
		return (printf("Error set table\n"));
	meal(&t);
	x = 0;
	while (x < t.nphilo)
		pthread_join(t.a_t[x ++], NULL);
	x = 0;
	pthread_mutex_destroy(&t.prt);
	while (x < t.nphilo)
		pthread_mutex_destroy(&t.f[x ++]);
	free(t.a_p);
	free(t.a_t);
	free(t.f);
	return (0);
}
