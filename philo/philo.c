/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:06:54 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 16:01:13 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_phil(t_all *all)
{
	write_with_timestamp(all, all->firstphil, "has taken a fork");
	usleep(all->ttd * 1000);
	write_with_timestamp(all, all->firstphil, "died");
}

int	main(int argc, char *argv[])
{
	t_all		all;

	if (argc < 5)
		exit_with_error("Not enough arguments");
	if (argc > 6)
		exit_with_error("Too many arguments");
	get_input(&all, argc, argv);
	all.exit = 0;
	gettimeofday(&all.start, NULL);
	init_phils(&all);
	pthread_mutex_init(&(all.m_time), NULL);
	pthread_mutex_init(&(all.m_write), NULL);
	pthread_mutex_init(&(all.m_meals), NULL);
	pthread_mutex_init(&(all.m_exit), NULL);
	if (all.nphilo == 1)
		lonely_phil(&all);
	else
	{
		create_threads(&all);
		checkroutine(&all);
		join_threads(&all);
	}
	clean_up(&all);
	return (0);
}
