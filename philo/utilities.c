/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:02:24 by sgasperi          #+#    #+#             */
/*   Updated: 2024/02/20 12:02:26 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**alloc_matrix(char **av, int ac)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = malloc(ac * sizeof(char **));
	while (++i < ac)
	{
		matrix[i - 1] = ft_substr(av[i], 0, ft_strlen(av[i]));
	}
	matrix[i - 1] = NULL;
	return (matrix);
}

int	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char			*c;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = (unsigned int)len;
	if (ft_strlen((char *)s) <= len)
		c = (char *) malloc(ft_strlen((char *)s) + 1);
	else
		c = (char *) malloc(j + 1);
	if (!c)
		return (NULL);
	if (!((unsigned int) ft_strlen((char *)s) < start))
	{
		while (s[i] != '\0' && i < j)
		{
			c[i] = s[start];
			i++;
			start++;
		}
	}
	c[i] = '\0';
	return (c);
}

void	ft_free_matrix(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}
