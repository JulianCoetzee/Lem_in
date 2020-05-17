/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenmike <jenmike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:03:27 by jenmike           #+#    #+#             */
/*   Updated: 2020/05/17 11:58:06 by jenmike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			visit_check(t_room *s_room, int room_nbr)
{
	t_room			*exploring;

    exploring = s_room;
	while (exploring)
	{
		if (exploring->r_nbr == room_nbr && exploring->visit_check == 1)
			return (1); //visited
		exploring = exploring->next;
	}
	return (0); //unvisited
}

static int			*path_array(t_room *s_room, int *room,
		int len, int total_links)
{
	int				i;
	int				j;
	t_links			*explore;
	int				*path_array;

	i = 0;
	j = 0;
	if (!(path_array = (int*)malloc(sizeof(int) * total_links)))
		error_out(4);
	while (i < len)
	{
		explore = s_room->links_pf;
		while (explore)
		{
			if (explore->from_room == room[i] && visit_check(s_room, explore->to_room) == 0)
				path_array[j++] = explore->to_room;
			explore = explore->next;
		}
		i++;
	}
	return (path_array);
}

static int			get_all_links(t_room *s_room, int *room, int len)
{
	int				i;
	t_links			*explore;
	int				total_links;

	i = 0;
	total_links = 0;
	while (i < len)
	{
		explore = s_room->links_pf;
		while (explore)
		{
			if (explore->from_room == room[i] && visit_check(s_room, explore->to_room))
				total_links++;
			explore = explore->next;
		}
		i++;
	}
	return (total_links);
}

void    	get_paths(t_room *s_room, int moves, int *room, int len)
{
	int				i;
	int				*p_array;
	int				total_links;

	i = 0;
	total_links = 0;
	while (i < len)
	{
		enter_room(s_room, room[i]);
		if (room[i] == s_room->end_r->r_nbr)
		{
			exit_room(s_room, room[i]);
			s_room->q_path = moves;
			return ;
		}
		i++;
	}
	if (!(total_links = get_all_links(s_room, room, len)))
		return ;
	p_array = path_array(s_room, room, len, total_links);
	get_paths(s_room, moves + 1, p_array, total_links);
	i = 0;
	while (i < len)
		exit_room(s_room, room[i++]);
	free(p_array);
}

