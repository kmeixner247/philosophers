/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:08:56 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 16:10:01 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phil_ded(t_all *all, t_phil *phil)
{
	write_with_timestamp(all, phil, "died");
	pthread_mutex_lock(&(all->m_exit));
	all->exit = -1;
	pthread_mutex_unlock(&(all->m_exit));
}

void	exit_with_error(char *error)
{
	printf("%s\n", error);
	exit (-1);
}
