#include "philo.h"

void	ft_create_thread(t_data data)
{
	int			i;
	pthread_t	supervisor;

	i = 0;
	pthread_create(&supervisor, NULL, &ft_monitor, &data.philos);
	while (i < data.philos->philo_nb)
	{
		pthread_create(&data.philos[i].t1, NULL, ft_routine, &data.philos[i]);

		i++;
	}
}
