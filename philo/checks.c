/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:03:25 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 16:03:39 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_exit(t_all *all)
{
	int	r;

	pthread_mutex_lock(&(all->m_exit));
	r = all->exit;
	pthread_mutex_unlock(&(all->m_exit));
	if (r)
		return (1);
	else
		return (0);
}

int	checkmeals(t_all *all)
{
	t_phil	*tmp;

	tmp = all->firstphil;
	while (tmp)
	{
		pthread_mutex_lock(&(all->m_meals));
		if (tmp->meals_eaten < all->meals)
		{
			pthread_mutex_unlock(&(all->m_meals));
			return (0);
		}
		pthread_mutex_unlock(&(all->m_meals));
		tmp = tmp->nextphil;
	}
	return (1);
}

void	checkroutine(t_all *all)
{
	t_phil		*phil;
	t_timeval	now;
	int			tdiff;

	while (!(all->exit))
	{
		gettimeofday(&now, NULL);
		phil = all->firstphil;
		while (phil && !(all->exit))
		{
			pthread_mutex_lock(&(all->m_time));
			tdiff = (now.tv_sec - phil->lastmeal.tv_sec) * 1000;
			tdiff += (now.tv_usec - phil->lastmeal.tv_usec) / 1000;
			pthread_mutex_unlock(&(all->m_time));
			if (tdiff >= all->ttd)
				phil_ded(all, phil);
			phil = phil->nextphil;
		}
		if (all->meals > 0 && checkmeals(all))
			all->exit = 1;
		usleep(1000);
	}
}
