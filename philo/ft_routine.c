#include "philo.h"

void	ft_thinking(t_philo *philo)
{
	printf("%d %d is thinking\n", philo->start_time, philo->id);
}

void	ft_sleeping(t_philo *philo)
{
	printf("%d %d is sleeping\n", philo->start_time, philo->id);
	usleep(philo->time_to_sleep);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%d %d has taken a fork\n", philo->start_time, philo->id);
	if (philo->philo_nb == 1)
		//philo should die?
	pthread_mutex_lock(philo->l_fork);
	printf("%d %d has taken a fork\n", philo->start_time, philo->id);
	philo->eating = 1;
	printf("%d %d is eating\n", philo->start_time, philo->id);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*ft_routine(void *param)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)param;
	while (philo[i].dead == 0)
	{
		ft_sleeping(philo);
		ft_eating(philo);
		ft_thinking(philo);
		i++;
	}
	return (param);
}
