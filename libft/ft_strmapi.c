/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:20:06 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 16:08:48 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
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
		nstr[i] = f(i, str[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
