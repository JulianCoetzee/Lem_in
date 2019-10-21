/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:55:54 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 12:45:25 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i--)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	}
	return (dst);
}
