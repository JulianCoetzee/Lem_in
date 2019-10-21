/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:23:58 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 16:29:38 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wrdcnt(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	s;
	char	**splits;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (!(splits = (char **)malloc(sizeof(char *) * (ft_wrdcnt(str, c)) + 1)))
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
			s = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (s < i)
			splits[j++] = ft_strsub(str, s, (i - s));
	}
	splits[j] = NULL;
	return (splits);
}
