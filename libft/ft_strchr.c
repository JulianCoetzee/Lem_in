/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:05:34 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/07/05 16:23:38 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t		i;
	const char	cc = (char)c;

	i = 0;
	while (str[i] && str[i] != cc)
		i++;
	if (str[i] == c)
		return (char *)&str[i];
	return (NULL);
}
