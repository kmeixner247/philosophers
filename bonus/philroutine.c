/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philroutine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:06:28 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 14:47:54 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	phil_eat(t_all *all, t_phil *phil)
{
	int	eating;

	eating = 0;
	sem_wait(all->forks);
	write_with_timestamp(all, phil, "takes a fork");
	sem_wait(all->forks);
	write_with_timestamp(all, phil, "takes a fork");
	sem_wait(all->time);
	gettimeofday(&(phil->lastmeal), NULL);
	sem_post(all->time);
	write_with_timestamp(all, phil, "is eating");
	(phil->meals_eaten)++;
	if (phil->meals_eaten == all->meals)
		sem_post(all->phils_done);
	while (eating <= (all->tte))
	{
		sem_wait(all->time);
		eating = gettime(phil->lastmeal);
		sem_post(all->time);
		if (check_exit(all, phil))
			break ;
		usleep(50);
	}
	sem_post(all->forks);
	sem_post(all->forks);
}

static void	phil_sleep(t_all *all, t_phil *phil)
{
	t_timeval	sleepstart;

	write_with_timestamp(all, phil, "is sleeping");
	gettimeofday(&sleepstart, NULL);
	while (gettime(sleepstart) <= (all->tts))
	{
		if (check_exit(all, phil))
			break ;
		usleep(50);
	}
}

static void	phil_think(t_all *all, t_phil *phil)
{
	write_with_timestamp(all, phil, "is thinking");
}

void	phil_ded(t_all *all, t_phil *phil)
{
	sem_wait(all->write);
	printf("%dms: Philosopher %d died\n", gettime(all->start), phil->id);
	sem_wait(all->dead);
	phil->dead = 1;
	sem_post(all->dead);
}

void	philroutine(t_all *all, t_phil *phil)
{
	pthread_t	deaththread;

	usleep(1000);
	all->forks = sem_open("/forks", 0);
	all->write = sem_open("/write", 0);
	all->dead = sem_open("/dead", 0);
	all->time = sem_open("/time", 0);
	all->phils_done = sem_open("/phils_done", 0);
	pthread_create(&deaththread, NULL, deathcheck, (void *)phil);
	if ((phil->id) % 2)
		usleep(1000);
	while (42)
	{
		if (check_exit(all, phil))
			break ;
		phil_eat(all, phil);
		if (check_exit(all, phil))
			break ;
		phil_sleep(all, phil);
		if (check_exit(all, phil))
			break ;
		phil_think(all, phil);
	}
	pthread_join(deaththread, NULL);
}
