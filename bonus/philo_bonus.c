/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:23:04 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 15:37:18 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_childs(t_all *all)
{
	t_phil	*phil;
	int		pid;

	phil = all->firstphil;
	pid = fork();
	phil->pid = pid;
	while (pid && phil->nextphil)
	{
		if (pid)
		{
			phil = phil->nextphil;
			pid = fork();
			phil->pid = pid;
		}
	}
	if (!pid)
		philroutine(all, phil);
	else
	{
		parent(all);
	}	
}

void	lonely_phil(t_all *all)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		all->time = sem_open("/time", 0);
		printf("%dms: Philosopher 1 has taken a fork\n", gettime(all->start));
		usleep(all->ttd * 1000);
		printf("%dms: Philosopher 1 died\n", gettime(all->start));
		sem_close(all->time);
	}
	else
		waitpid(-1, NULL, 0);
}

int	main(int argc, char *argv[])
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (argc < 5)
		exit_with_error("Not enough arguments");
	if (argc > 6)
		exit_with_error("Too many arguments");
	get_input(all, argc, argv);
	gettimeofday(&(all->start), NULL);
	init_phils(all);
	open_semaphores(all);
	if (all->nphil > 1)
		create_childs(all);
	else
		lonely_phil(all);
	clean(all);
	return (0);
}
