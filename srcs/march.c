/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:00:57 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 21:00:15 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    ant_march(char ***paths, int ant_total)
{
	t_march *move_out;

	move_out = (t_march *)ft_memalloc(sizeof(t_march));
	move_out->ant_total = ant_total;
	move_out->route_total = path_count(paths);
	move_out->path_sizes = path_sizes(paths, move_out->route_total);
	move_out->ants = (int *)ft_memalloc(sizeof(int) 
							* move_out->route_total + 1);
	if (move_out->route_total == 1 || ant_total == 1)
		single_file(paths[0], ant_total, move_out->path_sizes[0]);
	else
	{
		if (!(move_out->route_total = 
			ant_routes_used(ant_total, move_out->path_sizes)))
			single_file(paths[0], ant_total, move_out->path_sizes[0]);
		else
		{
			ant_columns(move_out);
			columns(paths, move_out);
		}
	}
	free_int_array(&(move_out->ants));
	free_int_array(&(move_out->path_sizes));
	free(move_out);
	move_out = NULL;
}

void    single_file(char **path, int ant_total, int path_size)
{
	t_move  *move;
	int     i;
	
	move = make_move(path, path_size);
	i = 1;
	while (i < ant_total + path_size)
	{
		if (i <= ant_total)
			ant_turn(move, i, path_size);
		else
			ant_turn(move, 0, path_size);
		move_output(move, path_size);
		ft_putchar('\n');
		i++;
	}
	free_move(&move);
}

void    ant_turn(t_move *move, int next_ant, int path_size)
{
	while (path_size)
	{
		move[path_size].ant = move[path_size - 1].ant;
		path_size--;
	}
	//start room (move[0]) gets next ant placed
	move[0].ant = next_ant;
}

void    ant_columns(t_march *move_out)
{
	int ants;
	int i;
	int rt;

	ants = move_out->ant_total;
	i = 0;
	rt = move_out->route_total;
	while (i < move_out->route_total)
	{
		while (move_out->ants[i] + move_out->path_sizes[i] 
						< move_out->path_sizes[rt])
		{
			move_out->ants[i]++;
			ants--;
		}
		i++;
	}
	i = 0;
	while (ants--)
	{
		move_out->ants[i++]++;
		if (i > move_out->route_total)
			i = 0;
	}
}

void    columns(char ***paths, t_march *move_out)
{
	t_move **moves;
	int     turns;

	move_out->i = 1;
	moves = make_moves(paths, move_out->path_sizes, move_out->route_total);
	turns = turn_total(move_out);
	move_out->path_size_sum = path_size_sum(move_out->path_sizes);
	while (turns--)
	{
		turn_loop(move_out, moves);
		out_loop(move_out, moves);
		if (turns + 1)
		{
			ft_putchar('\n');
		}
	}
	free_move_array(&moves);
}