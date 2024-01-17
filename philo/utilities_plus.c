#include "philo.h"

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return(write(1, "gettimeofday error\n", 19));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
