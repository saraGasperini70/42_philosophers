#include "philo.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	neg;
	int	n;

	c = 0;
	neg = 1;
	n = 0;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == 32)
	{
		c++;
	}
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			neg *= -1;
		c++;
	}
	while (str[c] >= 48 && str[c] <= 57)
	{
		n = n * 10 + str[c] - 48;
		c++;
	}
	return (n * neg);
}

