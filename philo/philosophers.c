#include "philo.h"

static char	**ft_av_in_matrix(char **av)
{
	int	i;
	int	j;
	char	**matrix;

	i = 1;
	j = 0;
	matrix = malloc(sizeof(av));
	while (av)
	{
		matrix[j] = av[i];
		i++;
		j++;
	}
	return (matrix);
}

int	main(int ac, char **av)
{
	char	**matrix;
	t_data	*data;

	data = NULL;
	if (ac == 2 && ft_strcmp(av[1], " ") == 0)
		matrix = ft_split(av[1], ' ');
	else
		matrix = ft_av_in_matrix(av);		
	ft_check_input(ac, av);
	ft_data_init(matrix, data);
	ft_philo_init(data);
	pthread_create(data->tid, NULL, &ft_routine, data);
	ft_free_matrix(matrix);
}
