/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:08:25 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/05 20:42:02 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_input(t_all *all, int argc, char **argv)
{
	if (checkstr(argv[1]))
		exit_with_error("Invalid input for the number of philosophers");
	else
		all->nphilo = ft_atoi(argv[1]);
	if (checkstr(argv[2]))
		exit_with_error("Invalid input for the time to die");
	else
		all->ttd = ft_atoi(argv[2]);
	if (checkstr(argv[3]))
		exit_with_error("Invalid input for the time to eat");
	else
		all->tte = ft_atoi(argv[3]);
	if (checkstr(argv[4]))
		exit_with_error("Invalid input for the time to sleep");
	else
		all->tts = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (checkstr(argv[5]))
			exit_with_error("Invalid input for meals to eat");
		else
			all->meals = ft_atoi(argv[5]);
	}
	else
		all->meals = -1;
}
