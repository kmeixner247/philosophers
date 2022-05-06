/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:48:09 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 14:32:53 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <pthread.h>
# include <signal.h>

typedef struct timeval	t_timeval;
typedef struct s_all{
	t_timeval		start;
	int				nphil;
	int				ttd;
	int				tte;
	int				tts;
	int				meals;
	sem_t			*phils_done;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*dead;
	sem_t			*time;
	struct s_phil	*firstphil;
}			t_all;

typedef struct s_phil{
	int				id;
	int				pid;
	int				meals_eaten;
	int				dead;
	t_timeval		lastmeal;
	struct s_phil	*nextphil;
	t_all			*all;
}				t_phil;

//		input.c
void	get_input(t_all *all, int argc, char **argv);

//		ft_atoi.c
int		checkstr(char *str);
int		ft_atoi(char *str);

//		exits.c
void	exit_with_error(char *error);

//		time.c
int		gettime(t_timeval start);

//		philroutine.c
void	philroutine(t_all *all, t_phil *phil);
void	phil_ded(t_all *all, t_phil *phil);

//		utils.c
void	write_with_timestamp(t_all *all, t_phil *phil, char *str);

//		parent.c
void	parent(t_all *all);

//		clean.c
void	clean(t_all *all);

//		init.c
void	open_semaphores(t_all *all);
void	init_phils(t_all *all);

//		checks.c
void	*deathcheck(void *mystruct);
int		check_exit(t_all *all, t_phil *phil);

#endif
