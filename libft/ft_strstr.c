/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:06:23 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/12 11:16:01 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *stack, const char *ndl)
{
	size_t i;
	size_t j;

	i = 0;
	if (stack[0] == '\0' && ndl[0] == '\0')
		return ((char *)stack);
	while (stack[i] != '\0')
	{
		j = 0;
		while (stack[i + j] == ndl[j] && ndl[j] != '\0')
			j++;
		if (ndl[j] == '\0')
			return ((char *)stack + i);
		i++;
	}
	return (NULL);
}
