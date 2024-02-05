#include "philo.h"

void	ft_print_msg(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_current_time() - philo->start_time;
	if (!ft_check_dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	ft_check_philo_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (ft_get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	ft_philo_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philo_nb)
	{
		if (ft_check_philo_dead(&philo[i], philo[i].time_to_die))
		{
			ft_print_msg("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_philos_eaten(t_philo *philo)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philo->eat_times == -1)
		return (0);
	while (i < philo[0].philo_nb)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].eat_times)
			finished_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finished_eating == philo[0].philo_nb)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
		if (ft_philo_dead(philo) == 1 || ft_philos_eaten(philo) == 1)
			break ;
	return (param);
}

