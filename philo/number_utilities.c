/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:01:24 by sgasperi          #+#    #+#             */
/*   Updated: 2024/02/20 12:01:25 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnumber(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
	{
		if (av[i] == '-')
			ft_error(7);
		i++;
	}
	while (av[i] && ft_isdigit(av[i]))
	{
		i++;
	}
	if (av[i] != '\0' && !ft_isdigit(av[i]))
	{
		return (0);
	}
	return (1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}
