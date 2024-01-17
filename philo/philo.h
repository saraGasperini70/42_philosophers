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
int	ft_init(char **av, t_data *data, pthread_mutex_t *forks, t_philo *philos);

/*utilities*/
int		ft_atoi(const char *str);
char	**alloc_matrix(char **av, int ac);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
void	ft_free_matrix(char **av);

/*utilities_plus*/
size_t	ft_get_current_time(void);

#endif
