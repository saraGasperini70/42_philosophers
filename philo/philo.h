/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:00:25 by sgasperi          #+#    #+#             */
/*   Updated: 2024/02/20 12:00:55 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "structs.h"

/*ft_routine*/
int		ft_check_dead(t_philo *philo);
void	*ft_routine(void *param);

/*ft_split*/
char	**ft_split(const char *s, char c);

/*input_checks*/
void	ft_error(int err);
void	ft_check_input(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);

/*number_utilities*/
int		ft_isnumber(char *av);
int		ft_isdigit(char c);
int		ft_issign(char c);

/*philo_init*/
void	ft_data_init(t_philo *philos, t_data *data);
void	ft_init_input(char **av, t_philo *philo);
void	ft_philo_init(char **av, t_philo *philos, t_data *data,
			pthread_mutex_t *forks);
void	ft_forks_init(pthread_mutex_t *forks, int forks_nb);

/*utilities*/
int		ft_atoi(const char *str);
char	**alloc_matrix(char **av, int ac);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
void	ft_free_matrix(char **av);

/*utilities_plus*/
size_t	ft_get_current_time(void);
void	ft_destroy_all(char *str, t_data *data, pthread_mutex_t *forks);
int		ft_usleep(size_t millisecs);

/*threads*/
void	*ft_monitor(void *param);
void	ft_print_msg(char *str, t_philo *philo, int id);
int		ft_create_thread(t_data *data, pthread_mutex_t *forks);

#endif
