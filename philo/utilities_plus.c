/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:55:17 by sgasperi          #+#    #+#             */
/*   Updated: 2024/02/20 11:56:14 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (write(2, "gettimeofday error\n", 19));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_destroy_all(char *str, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	printf("%s\n", str);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
	while (i < data->philos->philo_nb)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	ft_usleep(size_t millisecs)
{
	size_t	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < millisecs)
		usleep(500);
	return (0);
}
