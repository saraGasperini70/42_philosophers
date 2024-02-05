#include "philo.h"
/*Need: function to check if any of the philos are dead; another to check if all have eaten eat_times*/

int	ft_philo_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		if ((* philo[i].dead) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_philos_eaten(t_philo *philo)
{
	printf("%d\n", philo->id);
	return (1);
}

void	*ft_monitor(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (ft_philo_dead(philo) == 1 || ft_philos_eaten(philo) == 1)
		{
			break ;
		}
	}
	return (0);
}

