/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giantewok <giantewok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 12:16:49 by jenmike           #+#    #+#             */
/*   Updated: 2020/05/18 10:19:46 by giantewok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//path_checker makes sure a found path is recorded only once by 
//removing link in room between start & end. used in paths.c

char			**path_checker(t_room *room)
{
	int		length;
	char	**path_arr;
	t_room	*tmp;

	length = 0;
	tmp = room;
	while (tmp && ++length)
		tmp = tmp->prev;
	if (!(path_arr = (char **)malloc(sizeof(char *) * (length + 1))))
		return (NULL);
	path_arr[length] = NULL;
	if (room->prev->start == 1)
	{	
		free_links(room->prev);
	}
	while (length)
	{
		if (room->start == 0)
			free_links(room);
		path_arr[--length] = room->name;
		room = room->prev;
	}
	return (path_arr);
}

//returns a total path count

int		all_paths(t_room *room)
{
	int i;
	int all_paths;
	int check;

	all_paths = 0;
	while (room && room->start != 1 && room->start != -1)
		room = room->next;
	check = room->start;	
    i = RESET;
	if (!room)
		return (0);
    while (room->links[i])
		i++;
	all_paths = i;
	room = room->next;
    while (room && room->start != check * -1)
		room = room->next;
    i = RESET;
	if (!room)
		return (0);
	while (room->links[i])
		i++;
	if (i < all_paths)
		all_paths = i;
	return (all_paths);
}

static void		del_path(t_room *room)
{	
	while (room)
    {
	    if (room->len)
		    room->len = -1;
	    room = room->next;
    }	
}

void	pathfinder(char ***all_paths, t_room *room)
{
	int	i;

	i = 0;
	all_paths[0] = get_paths(room);
	while (all_paths[i++])
	{	
		del_path(room);
		all_paths[i] = get_paths(room);
	}
	if (!(all_paths[0]))
	{
		free(all_paths);
		error_out(2);
	}
}

char	***paths_found(t_room *rooms)
{
	char	***paths_found;
	int		all_pathsn;

	if (!(all_pathsn = all_paths(rooms)))
	{
		error_out(2);
		return (NULL);
	}
	if (!(paths_found = (char ***)malloc(sizeof(char **) * (all_pathsn + 1))))
	{
		error_out(4);
		return (NULL);
	}
	pathfinder(paths_found, rooms);
	return (paths_found);
}