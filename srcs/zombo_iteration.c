/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombo_iteration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:32 by giantewok         #+#    #+#             */
/*   Updated: 2020/05/18 11:43:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			turn_quan(t_march *march)
{
	int	quant;
	int	i;

	i = 0;
	quant = (march->dist[0] + march->ants[0]);
	while (march->dist[++i])
		if (march->dist[i] + march->ants[i] > quant)
			quant = march->dist[i] + march->ants[i];
	return (quant - 1);
}

void		turn_iter(t_march *march, t_move **moves)
{
	int	j;

	j = 0;
	while (j <= march->route_tot && (march->i
             < march->ant_tot + march->route_dist_tot))
	{
		ant_turn(moves[j], (march->ants[j]-- > 0) ? march->i++ : 0,
				march->dist[j]);
		j++;
	}
}

static int	check_move(t_move *move, int dist)
{
	if (move && dist)
		return (1);
	else
		return (0);
}

void		put_iter(t_march *march, t_move **moves)
{
	int		j;

	j = 0;
	while (j <= march->route_tot)
	{
		put_move(moves[j], march->dist[j]);
		j++;
		if (check_move(moves[j], march->dist[j]))
			ft_putchar(' ');
		else
			j++;
	}
}
