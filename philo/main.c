/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:56:01 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/10 18:42:47 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	t;
	int		x;

	x = 0;
	if (!(argc == 5 || argc == 6))
		return (printf("Number of arguments is incorrect\nError\n"));
	if (set_table(argc, argv, &t) || gettimeofday(&t.st, NULL))
		return (printf("Error\n"));
	//printf("Done setup\n");
	//printf("test : %d\n", t.a_p[0].n_e);
	while (x < t.nphilo)
	{
		t.a_p[x].t_e = t.st;
		t.a_p[x].p_n = x;
		//printf("Creating thread #%d\n", x);
		if (pthread_create(&t.a_t[x], NULL, &routine, &t.a_p[x]))
			return (printf("Thread Error\n"));
		x += 2;
	}
	x = 1;
	while (x < t.nphilo)
	{
		t.a_p[x].t_e = t.st;
		t.a_p[x].p_n = x;
		//printf("Creating thread #%d\n", x);
		if (pthread_create(&t.a_t[x], NULL, &routine, &t.a_p[x]))
			return (printf("Thread Error\n"));
		x += 2;
	}
	while (t.al)
		usleep(1);
	x = 0;
	while (x < t.nphilo)
	{
		pthread_detach(t.a_t[x]);
		printf("Philo %d has been detached\n", x);
		x ++;
	}
	return (0);
}
