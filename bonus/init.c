/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:25:36 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 14:26:40 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_semaphores(t_all *all)
{
	sem_unlink("/forks");
	all->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, all->nphil);
	sem_unlink("/write");
	all->write = sem_open("/write", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("/dead");
	all->dead = sem_open("/dead", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("/time");
	all->time = sem_open("/time", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("/phils_done");
	all->phils_done = sem_open("/phils_done", O_CREAT | O_EXCL, 0644, 0);
}

void	init_phils(t_all *all)
{
	int		i;
	t_phil	*tmp;
	t_phil	*phil;

	i = 2;
	phil = malloc(sizeof(t_phil));
	phil->id = 1;
	phil->meals_eaten = 0;
	phil->dead = 0;
	phil->lastmeal = all->start;
	all->firstphil = phil;
	phil->all = all;
	while (i <= all->nphil)
	{
		tmp = malloc(sizeof(t_phil));
		tmp->id = i;
		tmp->meals_eaten = 0;
		tmp->dead = 0;
		tmp->lastmeal = all->start;
		phil->nextphil = tmp;
		tmp->all = all;
		phil = tmp;
		i++;
	}
	phil->nextphil = NULL;
}
