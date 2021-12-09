/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:00:47 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/09 20:51:30 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
**Includes all the functions nessessary for the initializing of the table and
**and the Philo
**also Hendrick sucks
*/

/*
**invite_guest initializes the guest list 
*/

t_philo	*invite_guest(t_table *t)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	printf("invite_guest\n");
	new->p_n = -1;
	new->n_e = 0;
	new->al = 1;
	new->t = t; //pointer??
	return (new);
}

/*
**Create guest list creates the t_p array
*/

int	create_guest_list(int nphilo, t_table *t, t_philo **a_p)
{
	pthread_t		*guest_num;
	pthread_mutex_t	*frk_ls;
	//t_philo			**guest_list;
	int				x;

	printf("create_guest_list\n");
	a_p = malloc(nphilo * sizeof(t_philo *));
	guest_num = malloc(nphilo * sizeof(pthread_t));
	frk_ls = malloc(nphilo * sizeof(pthread_mutex_t));
	if (!frk_ls || !a_p || !guest_num)
		return (1); // NEED TO FREE
	x = 0;
	while (x < nphilo)
	{
		if (pthread_mutex_init(&frk_ls[x], NULL))
			return (1);
		a_p[x] = invite_guest(t);
		x ++;
	}
	//a_p = guest_list;
	printf("test : %d\n", a_p[0]->n_e);
	t->a_t = guest_num;
	t->f = frk_ls;
	return (0);
}

/*
**get_dishes does input checking
*/

int	get_dishes(int argc, char **argv, t_table *t)// Need to use int_check.c to do some in checking
{
	printf("get_dishes\n");
	if (ft_argvdigitcheck(argv) || ft_argvemptycheck(argv))
		return (printf("Incorrect imputs\n"));
	t->nphilo = ft_atoi(argv[1]);
	if (t->nphilo < 1)
		return (printf("Not enough Philosopher\n"));
	t->t2d = ft_atoi(argv[2]);
	if (t->t2d < 0)
		return (printf("Time to die is too small\n"));
	t->t2e = ft_atoi(argv[3]);
	if (t->t2e < 0)
		return (printf("Time to eat is too small\n"));
	t->t2s = ft_atoi(argv[4]);
	if (t->t2s < 0)
		return (printf("Time to sleep is too small\n"));
	if (argc == 6)
	{
		t->stomach = ft_atoi(argv[5]);
		if (t->stomach < 0)
			return (printf("Time to sleep is too small\n"));
	}
	else
		t->stomach = -1;
	return (0);
}

/*
**Set Table initializes the table and all its values
*/

int	set_table(int argc, char **argv, t_table *t, t_philo **a_p)// need a freeing
{
	printf("set_table\n");
	if (get_dishes(argc, argv, t))
		return (1);
	if (create_guest_list(t->nphilo, t, a_p))
		return (2);
	printf("test : %d\n", a_p[0]->n_e);
	return (0);
}
