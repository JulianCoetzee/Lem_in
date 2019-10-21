/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:55:24 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/12 10:53:16 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ndst;
	char	*nsrc;
	size_t	i;

	ndst = (char *)dst;
	nsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if ((unsigned char)nsrc[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
