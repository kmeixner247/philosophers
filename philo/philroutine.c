/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philroutine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:57:39 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 15:42:25 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_all *all, t_phil *phil)
{
	pthread_mutex_lock(phil->lfork);
	write_with_timestamp(all, phil, "has taken a fork");
	pthread_mutex_lock(phil->rfork);
	write_with_timestamp(all, phil, "has taken a fork");
}

void	phil_eat(t_all *all, t_phil *phil)
{
	int	eating;

	eating = 0;
	take_forks(all, phil);
	pthread_mutex_lock(&(all->m_time));
	gettimeofday(&(phil->lastmeal), NULL);
	pthread_mutex_unlock(&(all->m_time));
	write_with_timestamp(all, phil, "is eating");
	while (eating <= (all->tte))
	{
		pthread_mutex_lock(&(all->m_time));
		eating = gettime(phil->lastmeal);
		pthread_mutex_unlock(&(all->m_time));
		if (check_exit(all))
			break ;
		usleep(50);
	}
	pthread_mutex_unlock(phil->lfork);
	pthread_mutex_unlock(phil->rfork);
	if (all->meals > 0)
	{
		pthread_mutex_lock(&(all->m_meals));
		(phil->meals_eaten)++;
		pthread_mutex_unlock(&(all->m_meals));
	}
}

void	phil_sleep(t_all *all, t_phil *phil)
{
	t_timeval	sleepstart;

	gettimeofday(&sleepstart, NULL);
	write_with_timestamp(all, phil, "is sleeping");
	while (gettime(sleepstart) <= (all->tts))
	{
		if (check_exit(all))
			break ;
		usleep(50);
	}
}

void	phil_think(t_all *all, t_phil *phil)
{
	write_with_timestamp(all, phil, "is thinking");
}

void	*philroutine(void	*mystruct)
{
	t_phil	*phil;
	t_all	*all;

	phil = (t_phil *)mystruct;
	all = phil->all;
	if ((phil->id) % 2)
		usleep(5000);
	while (1)
	{
		if (check_exit(all))
			break ;
		phil_eat(all, phil);
		if (check_exit(all))
			break ;
		phil_sleep(all, phil);
		if (check_exit(all))
			break ;
		phil_think(all, phil);
	}
	return (NULL);
}
