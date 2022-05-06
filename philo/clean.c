/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:37:04 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/05 16:45:13 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_all *all)
{
	t_phil	*tmp;

	tmp = all->firstphil;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->nextphil;
	}
}

void	clean_up(t_all *all)
{
	t_phil	*tmp;
	t_phil	*tmp2;

	pthread_mutex_destroy(&(all->m_write));
	pthread_mutex_destroy(&(all->m_time));
	pthread_mutex_destroy(&(all->m_meals));
	pthread_mutex_destroy(&(all->m_exit));
	tmp = all->firstphil;
	while (tmp)
	{
		pthread_mutex_destroy(tmp->lfork);
		free(tmp->lfork);
		tmp2 = tmp->nextphil;
		free(tmp);
		tmp = tmp2;
	}
}
