/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:47:03 by kmeixner          #+#    #+#             */
/*   Updated: 2022/05/06 16:06:50 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct timeval	t_timeval;
typedef struct s_all{
	t_timeval		start;
	int				nphilo;
	int				ttd;
	int				tte;
	int				tts;
	int				meals;
	struct s_phil	*firstphil;
	pthread_mutex_t	m_exit;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_meals;
	pthread_mutex_t	m_time;
	int				exit;
}				t_all;

typedef struct s_phil{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	struct s_phil	*nextphil;
	int				meals_eaten;
	t_timeval		lastmeal;
	t_all			*all;
}				t_phil;

//			utils.c
void		write_with_timestamp(t_all *all, t_phil *phil, char *str);

//			init.c
void		create_threads(t_all *all);
void		init_phils(t_all *all);

//			clean.c
void		join_threads(t_all *all);
void		clean_up(t_all *all);

//			exits.c
void		phil_ded(t_all *all, t_phil *phil);
void		exit_with_error(char *error);

//			checks.c
int			check_exit(t_all *all);
int			checkmeals(t_all *all);
void		checkroutine(t_all *all);

//			ft_atoi.c
int			ft_atoi(char *str);
int			checkstr(char *str);

//			input.c
void		get_input(t_all *all, int argc, char **argv);

//			philroutine.c
void		*philroutine(void	*mystruct);

//			time.c
int			gettime(t_timeval start);
#endif
