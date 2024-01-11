#include "philo.h"

void	ft_error()
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
		printf("Troppi argomenti / Non abbastanza argomenti\n");
		ft_error();
	}
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
		{
			printf("Non é un numero\n");
			ft_error();
		}
		i++;
	}
	if (!(ft_atoi(av[1]) >= 1))
	{
		printf("Non abbastanza filosofi\n");
		ft_error();
	}
}