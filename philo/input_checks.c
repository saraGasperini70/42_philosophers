#include "philo.h"

void	ft_error(void)
{
	printf("Error!\n");
	exit(EXIT_FAILURE);
}

void	ft_check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 6 || ac < 5)
	{
		ft_error();
	}
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
		{
			ft_error();
		}
		i++;
	}
	if (!(ft_atoi(av[1]) >= 1) || !(ft_atoi(av[2]) > 0)
		|| !(ft_atoi(av[3]) > 0) || !(ft_atoi(av[4]) > 0))
	{
		ft_error();
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
