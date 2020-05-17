/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 12:04:57 by jenmike           #+#    #+#             */
/*   Updated: 2020/05/17 20:50:00 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_links(t_room *room, int length)
{
	t_room **t_new_room;

	t_new_room = room->links;
	if (t_new_room)
	{
		while (*t_new_room)
		{
			if ((*t_new_room)->len == -1)
			{
				(*t_new_room)->len = length + 1;
				(*t_new_room)->prev = room;
			}
			t_new_room++;
		}
	}
}

// char			**pathfiller(t_room *room)
// {
// 	char	**path;
// 	int		length;
// 	t_room	*t_new_room;

// 	length = 0;
// 	t_new_room = room;
// 	while (t_new_room && ++length)
// 		t_new_room = t_new_room->prev;
// 	if (!(path = (char **)malloc(sizeof(char *) * (length + 1))))
// 		return (NULL);
// 	path[length] = NULL;
// 	while (length)
// 	{
// 		path[--length] = room->name;
// 		room = room->prev;
// 	}
// 	return (path);
// }

static int		put_linklen(t_room **temp, int len)
{
	get_links(*temp, len);
	*temp = (*temp)->next;
	return (0);
}

char			**get_paths(t_room *rooms)
{
	int		pnf;
	int		length;
	t_room	*t_new_room;

	t_new_room = rooms;
	length = 0;
	pnf = 0;
	while (!pnf)
	{
		if (t_new_room == rooms)
			pnf = 1;
		while (t_new_room && t_new_room->len != length)
			t_new_room = t_new_room->next;
		if (length == 0 && t_new_room)
			t_new_room->prev = NULL;
		if (t_new_room && t_new_room->start != -1)
		{
				pnf = put_linklen(&t_new_room, length);
				// t_new_room = (t_new_room)->next;
		}
		else if (t_new_room)
			return (path_checker(t_new_room));
		if (!t_new_room && ++length)
			t_new_room = rooms;
	}
	return (NULL);
}
