/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:56:01 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/09 20:52:28 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	t;
	t_philo	*a_p;
	int		x;

	x = 0;
	a_p = NULL;
	if (!(argc == 5 || argc == 6))
		return (printf("Number of arguments is incorrect\nError\n"));
	if (set_table(argc, argv, &t, &a_p) || gettimeofday(&t.st, NULL))
		return (printf("Error\n"));
	printf("Done setup\n");
	printf("test : %d\n", a_p[0].n_e);
	while (x < t.nphilo)
	{
		a_p[x].t_e = t.st;
		a_p[x].p_n = x;
		printf("Creating thread #%d\n", x);
		if (!(pthread_create(&t.a_t[x], NULL, &troutine, &a_p[x])))
			return (printf("Thread Error\n"));
		x ++;
	}
	x = 0;
	while (x < t.nphilo)
	{
		pthread_join(t.a_t[x], NULL);
		x++;
	}
	return (0);
}
