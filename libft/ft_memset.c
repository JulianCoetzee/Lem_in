/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:53:34 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/12 10:49:58 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	u;
	char			*str;
	size_t			i;

	u = (unsigned char)c;
	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = u;
		i++;
	}
	return (b);
}
