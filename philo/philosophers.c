#include "philo.h"

int	main(int ac, char **av)
{
	char	**matrix;
	t_data	*data;

	if (ac == 2 && ft_strcmp(av[1], " ") == 0)
		matrix = ft_split(av[1], " ");
	else
		matrix = alloc_matrix(**av, ac);
	ft_check_input(ac, av);
	ft_data_init(data, matrix);
	ft_philo_init(matrix, data);
	ft_free_matrix(matrix);
}
