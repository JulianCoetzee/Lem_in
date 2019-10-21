/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:23:25 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/19 16:54:18 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tstr;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (ft_strnew(0));
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
		j--;
	if (!(tstr = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (k < (j - i + 1))
	{
		tstr[k] = str[i + k];
		k++;
	}
	tstr[k] = '\0';
	return (tstr);
}
