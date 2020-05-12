/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 10:58:46 by jcoetzee          #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' ||
		c == '\n' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_can_atoi(char *str)
{
	char	*imax;
	int		i;
	int 	lorge;

	i = 0;
	lorge = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		imax = "2147483648";
	else
		imax = "2147483647";
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && *imax)
	{
		if (str[i++] > *imax)
			lorge = 1;
		imax++;
	}
	if (*imax || (!str[i] && !lorge))
		return (1);
	else
		return (0);
	return (-1);
}

/*
** returns 1 if can true
** returns 0 if str wont fit in  integer
** it should not get to the return -1
*/