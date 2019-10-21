/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:19:43 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 16:07:31 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	size_t	i;
	char	*nstr;

	if (str == NULL)
		return (NULL);
	i = 0;
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(str)) + 1);
	if (nstr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		nstr[i] = f(str[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
