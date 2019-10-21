/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:22:15 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/13 15:01:26 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*sstr;

	i = 0;
	sstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !sstr)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		sstr[i] = str[start + i];
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}
