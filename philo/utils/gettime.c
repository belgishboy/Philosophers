/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:45:28 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/09 20:14:46 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*int	t_fstart(int s_time)
{
	
}*/

int	get_start_time(int s_time)
{
	struct timeval	g_time;
	int				time;

	if (gettimeofday(&g_time, NULL))
		return (1);
	time = ((int)g_time.tv_usec) / 10000;
	if (s_time >= 0)
		return (time - s_time);
	return (time);
}
