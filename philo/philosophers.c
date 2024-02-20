/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:01:45 by sgasperi          #+#    #+#             */
/*   Updated: 2024/02/20 12:01:46 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];

	ft_check_input(ac, av);
	ft_data_init(philos, &data);
	ft_forks_init(forks, ft_atoi(av[1]));
	ft_philo_init(av, philos, &data, forks);
	ft_create_thread(&data, forks);
	ft_destroy_all("", &data, forks);
	return (0);
}
