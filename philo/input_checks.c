#include "philo.h"

void	ft_error(int err)
{
	if (err == 1)
		printf("Invalid argument count.\n");
	if (err == 2)
		printf("Invalid argument type: should be numbers.\n");
	if (err == 3)
		printf("Invalid number of philosophers.\n");
	if (err == 4)
		printf("Invalid time to die.\n");
	if (err == 5)
		printf("Invalid time to eat.\n");
	if (err == 6)
		printf("Invalid time to sleep.\n");
	if (err == 7)
		printf("Negative numbers are not allowed.\n");
	exit(EXIT_FAILURE);
}

void	ft_check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 6 || ac < 5)
	{
		ft_error(1);
	}
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
			ft_error(2);
		i++;
	}
	if (!(ft_atoi(av[1]) >= 1) || ft_atoi(av[1]) > 200)
		ft_error(3);
	if (!(ft_atoi(av[2]) > 0))
		ft_error(4);
	if (!(ft_atoi(av[3]) > 0))
		ft_error(5);
	if (!(ft_atoi(av[4]) > 0))
		ft_error(6);
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
