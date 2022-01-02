/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:04:39 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/28 13:18:16 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
**Contains all the actions the philopher can take
*/

int	death(t_philo *p)
{
	if (!p->al || get_time() - p->t_e >= p->t->t2d)
	{
		p->t->al = 0;
		p->al = 0;
		prt_status(p, p->t, 5, get_time());
		return (0);
	}
	return (1);
}
