/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:59:47 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 16:09:53 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	firstphil(t_all *all)
{
	t_phil			*phil;
	pthread_mutex_t	*fork;

	phil = malloc(sizeof(t_phil));
	phil->id = 1;
	phil->meals_eaten = 0;
	fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork, NULL);
	phil->lfork = fork;
	all->firstphil = phil;
	phil->all = all;
}

void	init_phils(t_all *all)
{
	t_phil			*phil;
	t_phil			*tmpphil;
	pthread_mutex_t	*fork;
	int				i;

	firstphil(all);
	i = 2;
	phil = all->firstphil;
	while (i <= (all->nphilo))
	{
		tmpphil = malloc(sizeof(t_phil));
		tmpphil->id = i;
		tmpphil->meals_eaten = 0;
		phil->nextphil = tmpphil;
		fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(fork, NULL);
		tmpphil->lfork = fork;
		phil->rfork = fork;
		tmpphil->all = all;
		phil = tmpphil;
		i++;
	}
	phil->rfork = all->firstphil->lfork;
	phil->nextphil = NULL;
}

void	create_threads(t_all *all)
{
	t_phil	*tmp;

	tmp = all->firstphil;
	while (tmp)
	{
		pthread_create(&(tmp->thread), NULL, philroutine, (void *)tmp);
		tmp = tmp->nextphil;
	}
}
