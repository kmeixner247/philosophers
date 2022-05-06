/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:44:12 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 13:26:26 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean(t_all *all)
{
	t_phil	*tmp;
	t_phil	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	sem_close(all->phils_done);
	sem_close(all->forks);
	sem_close(all->write);
	sem_close(all->dead);
	sem_close(all->time);
	tmp = all->firstphil;
	while (tmp)
	{
		tmp2 = tmp->nextphil;
		free(tmp);
		tmp = tmp2;
	}
	free(all);
}
