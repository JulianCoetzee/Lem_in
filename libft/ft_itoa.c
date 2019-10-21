/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:24:17 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/14 12:59:00 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *num;

	num = (char *)malloc(sizeof(char) * 2);
	if (num == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(num, "-2147483648"));
	if (n < 0)
	{
		num[0] = '-';
		num[1] = '\0';
		num = ft_strjoin(num, ft_itoa(-n));
	}
	else if (n >= 10)
		num = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		num[0] = n + '0';
		num[1] = '\0';
	}
	return (num);
}
