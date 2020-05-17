/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:56:57 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:00:27 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_move	*make_move(char **path, int path_size)
{
	int		i;
	t_move	*move;

	i = 0;
	move = (t_move *)ft_memalloc(sizeof(t_move) * (path_size + 1));
	while (i < path_size)
	{
		(move[i]).room = path[i + 1];
		(move[i++]).ant = 0;
	}
	move[i].room = NULL;
	return (move);
}

t_move	**make_moves(char ***path, int *path_sizes, int route_total)
{
	int		i;
	t_move	**moves;

	i = -1;
	moves = (t_move **)ft_memalloc(sizeof(t_move *) * (route_total + 2));
	while (++i < route_total + 1)
	{
		moves[i] = make_move(path[i], path_sizes[i]);
	}
	moves[i] = NULL;
	return (moves);
}