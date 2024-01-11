#include "philo.h"

int	main(int ac, char **av)
{
	char **matrix;

	if (ac == 2 && ft_strcmp(av[1], " ") == 0)
		matrix = ft_split(av[1], " ");
	else
		matrix = alloc_matrix(**av, ac);
	ft_check_input(ac, av);
	ft_philo_init(matrix);
	ft_free_matrix(matrix);
}
