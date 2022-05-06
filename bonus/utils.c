/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:15:26 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 12:39:16 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	write_with_timestamp(t_all *all, t_phil *phil, char *str)
{
	if (!(phil->dead))
	{
		sem_wait(all->write);
		printf("%dms: Philosopher %d %s\n", gettime(all->start), phil->id, str);
		sem_post(all->write);
	}
}
