#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

void	ft_error();
void	ft_check_input(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isnumber(char *av);
int		ft_isdigit(char c);
int		ft_issign(char c);

#endif
