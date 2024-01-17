#include "philo.h"

static void	ft_data_init(t_philo *philos, t_data *data)
{
	data->dead = 0;
	data->philos = philos;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
}

static void	ft_init_input(char **av, t_philo *philo)
{
	philo->philo_nb = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->eat_times = ft_atoi(av[5]);
	else
		philo->eat_times = -1;
}

static void	ft_philo_init(char **av, t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i > philos->philo_nb)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		ft_init_input(av, &philos[i]);
		philos[i].start_time = ft_get_current_time();
		philos[i].last_meal = ft_get_current_time();
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].dead = &data->dead;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].philo_nb - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

static void	ft_forks_init(pthread_mutex_t *forks, int forks_nb)
{
	int i;

	i = 0;
	while (i < forks_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	ft_init(char **av, t_data *data, pthread_mutex_t *forks, t_philo *philos)
{
	printf("%p\n", data);
	ft_data_init(philos, data);
	ft_forks_init(forks, ft_atoi(av[1]));
	ft_philo_init(av, philos, data, forks);
	return (0);
}
