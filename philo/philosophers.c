#include "philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];

	ft_check_input(ac, av);
	ft_init(av, &data, forks, philos);
	ft_create_thread(data);
	/*ft_destroy_all()*/
	return (0);
}
