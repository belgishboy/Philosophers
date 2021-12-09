/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:23:19 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/09 20:50:21 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_argvemptycheck(char **argv)
{
	size_t	x;

	x = 1;
	while (argv[x])
	{
		if (!ft_strlen(argv[x]))
			return (1);
		else if (ft_strlen(argv[x]) >= 12)
			return (1);
		x ++;
	}
	return (0);
}

/*
**argvdigitcheck checks all the argv values are digits
*/

int	ft_argvdigitcheck(char **argv)
{
	size_t	i;
	size_t	x;

	x = 1;
	while (argv[x])
	{
		i = 0;
		while (argv[x][i])
		{
			if (argv[x][i] == '-' && i == 0)
			{
				if (!(argv[x][1] >= 48 && argv[x][1] <= 57))
					return (1);
			}
			else if (!(argv[x][i] >= 48 && argv[x][i] <= 57))
				return (1);
			i ++;
		}
		x ++;
	}
	return (0);
}
