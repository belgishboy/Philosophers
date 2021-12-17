/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:45:28 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/17 14:02:45 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*int	t_fstart(int s_time)
{
	
}*/

long long	get_time(void)
{
	struct timeval	g_time;
	long long		time;

	if (gettimeofday(&g_time, NULL))
	{
		printf("TIME ERROR\n");
		return (-1);
	}
	time = (g_time.tv_sec) * 10000;
	time += (g_time.tv_usec) / 1000;
	return (time);
}
