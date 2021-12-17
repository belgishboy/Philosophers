/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:56:01 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/17 19:32:51 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	t;
	int		x;
	int		i;

	if (!(argc == 5 || argc == 6))
		return (printf("Number of arguments is incorrect\nError\n"));
	if (set_table(argc, argv, &t))
		return (printf("Error set table\n"));
	t.st = get_time();
	t.ct = t.st;	//printf("Done setup\n");
	x = 0;
	i = 0;
	while (i++ < 2)
	{
		while (x < t.nphilo)
		{
			t.a_p[x].t_e = t.st;
			t.a_p[x].p_n = x;
			if (pthread_create(&t.a_t[x], NULL, &routine, &t.a_p[x]))
				return (printf("Thread Error\n"));
			x += 2;
		}
		x = 1;
		usleep(250);
		t.ct = get_time();
	}
	while (t.al && t.d_e != t.nphilo)
	{
		t.ct = get_time();
		x = 0;
		while (x < t.nphilo)
		{
			if (t.a_p[x].t_e - t.ct >= t.t2d)
			{
				t.al = 0;
				t.a_p[x].al = 0;
				prt_status(&t.a_p[x], &t, 5);
				break;
			}
			x ++;
		}
	}
	x = 0;
	while (x < t.nphilo)
	{
		pthread_detach(t.a_t[x]);
		printf("Philo %d has been detached @ %lld \n", x, t.ct);
		x ++;
	}
	return (0);
}
