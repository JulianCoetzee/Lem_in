/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:22:41 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:31 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*js;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	js = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (js == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		js[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		js[i] = s2[j];
		i++;
		j++;
	}
	js[i] = '\0';
	return (js);
}
