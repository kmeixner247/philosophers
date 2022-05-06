/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:25:35 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 16:23:37 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*mealcheck(void *mystruct)
{
	t_all	*all;
	int		n;

	all = (t_all *)mystruct;
	n = all->nphil;
	while (n > 0)
	{
		sem_wait(all->phils_done);
		n--;
	}
	kill(all->firstphil->pid, SIGKILL);
	return (NULL);
}

void	parent(t_all *all)
{
	t_phil		*tmp;
	pthread_t	mealcheckthread;
	int			n;

	if (all->meals > 0)
		pthread_create(&mealcheckthread, NULL, &mealcheck, (void *)all);
	tmp = all->firstphil;
	waitpid(-1, NULL, 0);
	if (all->meals > 0)
	{
		n = all->nphil;
		while (n > 0)
		{
			sem_post(all->phils_done);
			n--;
		}
	}
	while (tmp)
	{
		kill(tmp->pid, SIGKILL);
		tmp = tmp->nextphil;
	}
}
