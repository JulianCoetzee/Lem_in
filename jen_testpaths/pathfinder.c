/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenmike <jenmike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:41:59 by jenmike           #+#    #+#             */
/*   Updated: 2020/05/17 11:56:11 by jenmike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			gen_room(t_room *s_room, int current_room)
{
	t_room			*explore;

	explore = s_room;
	while (explore && explore->r_nbr != current_room)
		explore = explore->next;
	if (!(s_room->tmp_room = (t_room *)malloc(sizeof(t_room))))
		error_out(4);
	s_room->tmp_room->name = ft_strdup(explore->name);
	s_room->tmp_room->r_nbr = explore->r_nbr;
	s_room->tmp_room->x = explore->x;
	s_room->tmp_room->y = explore->y;
	s_room->tmp_room->start = explore->start;
	s_room->tmp_room->end = explore->end;
	s_room->tmp_room->visit_check = UNVISITED;
	s_room->tmp_room->next = NULL;
	s_room->tmp_room->prev = NULL;
}

static void			gen_path(t_room *s_room, int current_room)
{
	gen_room(s_room, current_room);
	if (!s_room->path)
		s_room->path = s_room->tmp_room;
	else
	{
		s_room->tmp_room->next = s_room->path;
		s_room->path->prev = s_room->tmp_room;
		s_room->path = s_room->tmp_room;
	}
	s_room->tmp_room = NULL;
}

static void			p_generate(t_room *s_room, int moves, int current_room)
{
	t_links			*explore;

	explore = s_room->links_pf;
	if (moves > s_room->q_path)
		return ;
	enter_room(s_room, current_room);
	if (current_room == s_room->end_r->r_nbr && moves == s_room->q_path)
	{
		s_room->q_path = -2;
		exit_room(s_room, current_room);
		gen_path(s_room, current_room);
		return ;
	}
	while (explore)
	{
		if (explore->from_room == current_room && visit_check(s_room, explore->to_room) == UNVISITED)
			p_generate(s_room, moves + 1, explore->to_room);
		if (s_room->q_path == -2)
		{
			gen_path(s_room, current_room);
			return ;
		}
		explore = explore->next;
	}
	exit_room(s_room, current_room);
}

void			pathfinder(t_room *s_room)
{
	get_paths(s_room, 0, &s_room->start_r->r_nbr, 1);
	p_generate(s_room, 0, s_room->start_r->r_nbr);
}

