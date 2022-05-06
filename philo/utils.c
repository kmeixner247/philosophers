/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:58:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 15:59:03 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_with_timestamp(t_all *all, t_phil *phil, char *str)
{
	pthread_mutex_lock(&(all->m_write));
	pthread_mutex_lock(&(all->m_time));
	if (!check_exit(all))
		printf("%dms: Philosopher %d %s\n", gettime(all->start), phil->id, str);
	pthread_mutex_unlock(&(all->m_write));
	pthread_mutex_unlock(&(all->m_time));
}
