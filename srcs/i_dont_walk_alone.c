/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_dont_walk_alone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giantewok <giantewok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:53 by giantewok         #+#    #+#             */
/*   Updated: 2020/05/18 10:32:47 by giantewok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lemin.h"

static t_move	**make_moves(char ***route, int *dist, int sim_route)
{
	t_move	**moves;
	int		i;

	i = -1;
	moves = (t_move**)ft_memalloc(sizeof(t_move*) * (sim_route + 2));
	while (++i < sim_route + 1)
	{
		moves[i] = make_move(route[i], dist[i]);
	}
	moves[i] = NULL;
	return (moves);
}

static int		dist_tot(int *dist)
{
	int	sum;

	sum = 0;
	while (*dist)
		sum += *(dist++);
	return (sum);
}

void			multi_route(char ***route, t_march *march)
{
	t_move	**moves;
	int		turns;

	march->i = 1;
	moves = make_moves(route, march->dist, march->route_tot);
	turns = turn_quan(march);
	march->route_dist_tot = dist_tot(march->dist);
	while (turns--)
	{
		turn_iter(march, moves);
		put_iter(march, moves);
		if (turns + 1)
			ft_putchar('\n');
	}
	free_move_array(&moves);
	free_int_array(&(march->dist));
	free_march_array(march);
}
