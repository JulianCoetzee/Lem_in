/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:49:54 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/06/19 17:00:26 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *tlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	tlst = f(lst);
	nlst = tlst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tlst->next = f(lst);
		tlst = tlst->next;
	}
	return (nlst);
}
