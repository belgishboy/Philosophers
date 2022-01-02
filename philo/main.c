/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:56:01 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/28 13:38:23 by vheymans         ###   ########.fr       */
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
	}
	while (t.al)
	{
		// x = 0;
		// while (x < t.nphilo)
		// {
		// 	if (get_time() - t.a_p[x].t_e >= t.t2d)
		// 	{
		// 		t.al = 0;
		// 		t.a_p[x].al = 0;
		// 		prt_status(&t.a_p[x], &t, 5, get_time());
		// 		break ;
		// 	}
		// 	x ++;
		// }
		if (t.d_e >= t.nphilo)
		{
			t.al = 0;
			printf("done eating\n");
			break ;
		}
	}
	x = 0;
	printf("Exiting\n");
	//pthread_mutex_lock(&t.prt);
	while (x < t.nphilo)
	{
		printf("Philo %d had eaten %d times\n", x, t.a_p[x].n_e);
		pthread_join(t.a_t[x], NULL); // join kills 
		printf("%lld Philo %d has been joined \n", get_time(), x);
		x ++;
	}
	return (0);
}
