/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:43:05 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:43:05 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
** Function ft_calloc uses melloc and ft_bzero to make a pointer p and fill it
** with \0
*/

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;
	int		x;
	int		pos;

	p = malloc(nelem * elsize);
	if (!p)
		return (0);
	x = nelem * elsize;
	pos = 0;
	while (x > 0)
	{
		((unsigned char *)p)[pos] = '\0';
		x --;
		p ++;
	}
	return (p);
}
