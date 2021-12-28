/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:33:32 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/20 18:23:03 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
**
*/
void	prt_status(t_philo *phil, t_table *t, int status, long long time)
{
	pthread_mutex_lock(&t->prt);
	printf("%lld %d ", time - t->st, phil->p_n + 1);
	if (status == 1)
		printf("has taken a fork\n");
	else if (status == 2)
		printf("is eating\n");
	else if (status == 3)
		printf("is sleeping\n");
	else if (status == 4)
		printf("is thinking\n");
	else if (status == 5)
		printf("died\n");
	if (status < 5)
		pthread_mutex_unlock(&t->prt);
}

void	p_error(char *s)
{
	int	i;

	i = 0;
	
}