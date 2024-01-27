#include "philo.h"

void	ft_monitor(void *param)
{
	t_data	*data;
	int	i;

	i = 0;
	data = (t_data *)param;
	while (data->dead == 0)
	{
		if (data->philos[i].time_to_die > data->philos[i].last_meal
			&& data->philos[i].eating)
			data->dead = 1;
		if (data->philos[i].meals_eaten == data->philos[i].eat_times)
			data->dead = 1;
		i++;
	}
}

void	ft_create_thread(t_data data)
{
	int			i;
	pthread_t	*supervisor;

	i = 0;
	pthread_create(supervisor, NULL, &ft_monitor, &data.philos);
	while (i < data.philos->philo_nb)
	{
		pthread_create(&data.philos[i].t1, NULL, ft_routine, &data.philos[i]);

		i++;
	}
}
