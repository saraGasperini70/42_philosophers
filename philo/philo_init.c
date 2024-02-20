/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:01:37 by sgasperi          #+#    #+#             */
/*   Updated: 2024/02/20 12:02:13 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_data_init(t_philo *philos, t_data *data)
{
	data->dead = 0;
	data->philos = philos;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
}

void	ft_init_input(char **av, t_philo *philo)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->philo_nb = ft_atoi(av[1]);
	if (av[5])
		philo->eat_times = ft_atoi(av[5]);
	else
		philo->eat_times = -1;
}

void	ft_philo_init(char **av, t_philo *philos, t_data *data,
	pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
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

void	ft_forks_init(pthread_mutex_t *forks, int forks_nb)
{
	int	i;

	i = 0;
	while (i < forks_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
