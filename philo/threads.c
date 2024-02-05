#include "philo.h"

int	ft_create_thread(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	supervisor;

	i = 0;
	if (pthread_create(&supervisor, NULL, &ft_monitor, data->philos) != 0)
		ft_destroy_all("Error in thread creation.", data, forks);
	while (i < data->philos[0].philo_nb)
	{
		if (pthread_create(&data->philos[i].t1, NULL, ft_routine, &data->philos[i]) != 0)
			ft_destroy_all("Error in thread creation.", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(supervisor, NULL) != 0)
		ft_destroy_all("Error in thread joining.", data, forks);
	while (i < data->philos[0].philo_nb)
	{
		if (pthread_join(data->philos[i].t1, NULL) != 0)
			ft_destroy_all("Error in thread joining.", data, forks);
		i++;
	}
	return (0);
}
