/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:56:32 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/12 10:54:38 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*nstr;
	size_t	i;

	nstr = (char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)nstr[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
