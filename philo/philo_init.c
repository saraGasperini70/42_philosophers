#include "philo.h"

void	ft_data_init(char **matrix, t_data *data)
{
	data->philo_nb = ft_atoi(matrix[0]);
	data->death_time = (__uint64_t) ft_atoi(matrix[1]);
	data->eat_time = (__uint64_t) ft_atoi(matrix[2]);
	data->sleep_time = (__uint64_t) ft_atoi(matrix[3]);
	if (matrix[4])
		data->meals_nb = ft_atoi(matrix[4]);
	pthread_mutex_init(data->forks, NULL);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
}

void	ft_philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i >= data->philo_nb)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].time_to_eat = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		pthread_mutex_init(&data->philos[i].l_fork, NULL);
		pthread_mutex_init(&data->philos[i].r_fork, NULL);
		i++;
	}
}
