#include "philo.h"
/*
void	*ft_routine(void *param)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)param;
	while (philo->data->dead == 0)
	{
		if (philo[i].eating == 0)
		{
			pthread_mutex_lock(&philo[i].r_fork);
			pthread_mutex_lock(&philo[i].l_fork);
			philo[i].eating = 1;
			usleep(philo[i].data->sleep_time);
		}
		else
				printf("%d is thinking\n", philo[i].id);
		i++;
	}
	return (param);
}
*/
