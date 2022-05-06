/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:29:35 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 14:29:51 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_exit(t_all *all, t_phil *phil)
{
	int	r;

	sem_wait(all->dead);
	r = phil->dead;
	sem_post(all->dead);
	if (r)
		return (1);
	else
		return (0);
}

void	*deathcheck(void *mystruct)
{
	t_phil		*phil;
	t_all		*all;
	t_timeval	now;
	int			tdiff;
	int			dead;

	phil = (t_phil *)mystruct;
	all = phil->all;
	dead = 0;
	while (!dead)
	{
		gettimeofday(&now, NULL);
		sem_wait(all->time);
		tdiff = (now.tv_sec - phil->lastmeal.tv_sec) * 1000;
		tdiff += (now.tv_usec - phil->lastmeal.tv_usec) / 1000;
		sem_post(all->time);
		if (tdiff >= all->ttd)
			phil_ded(all, phil);
		sem_wait(all->dead);
		dead = phil->dead;
		sem_post(all->dead);
	}
	return (NULL);
}
