#include "philo.h"

void	*ft_routine(void *param)
{
	int	i;
	t_data	*data;

	i = 0;
	data = (t_data *)param;	
	while (/*until a philo dies ||*/ data->philos[i].time_to_eat <= data->meals_nb)
	{
		if (data->philos[i].eating == 0)
		{
			pthread_mutex_lock(&data->philos[i].r_fork);
			pthread_mutex_lock(&data->philos[i].l_fork);
			data->philos[i].eating = 1;
			usleep(data->sleep_time);
		}
		else
				printf("%d is thinking\n", data->philos[i].id);
		i++;
	}
}