/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:05:57 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 13:18:37 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	const char	cc = (char)c;
	char		*r;

	i = 0;
	r = NULL;
	while (i <= ft_strlen(str))
	{
		if (str[i] == cc)
		{
			r = (char *)&str[i];
		}
		i++;
	}
	return (r);
}
