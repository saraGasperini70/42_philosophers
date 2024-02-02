#include "philo.h"

int	ft_check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	ft_thinking(t_philo *philo)
{
	ft_print_msg("is thinking", philo, philo->id);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_msg("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_msg("has taken a fork", philo, philo->id);
	if (philo->philo_nb == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	ft_print_msg("has taken a fork", philo, philo->id);
	philo->eating = 1;
	ft_print_msg("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*ft_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!ft_check_dead(philo))
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (param);
}
