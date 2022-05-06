/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:09:16 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/05 21:05:40 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	gettime(t_timeval start)
{
	t_timeval	tv;
	int			tdiff;

	gettimeofday(&tv, NULL);
	tdiff = (tv.tv_sec - start.tv_sec) * 1000;
	tdiff += (tv.tv_usec - start.tv_usec) / 1000;
	return (tdiff);
}
