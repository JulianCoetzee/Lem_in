/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_roads_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:25 by giantewok         #+#    #+#             */
/*   Updated: 2020/05/18 11:42:38 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

/*
** route_quan: if it only counts 1, the sing_route method is used
**				otherwise ish gets split & 2+ roads diverge
*/
int		route_quan(int n, int *dist)
{
	int splits;
	int i;

	i = 1;
	splits = 0;
	if ((n - i) + dist[0] >= i + dist[1])
	{
		while ((n - i) + dist[0] >= i + dist[1])
			i++;
		splits++;
	}
	if (dist[2])
		splits += route_quan(i - 1, dist + 1);
	return (splits);
}

/*
**sep_ant: splits ants up
*/

void    sep_ant(t_march *march)
{
	int i;
	int j;

	j = march->ant_tot;
	i = 0;
	while (march->route_tot > i)
	{
		while (march->ants[i] + march->dist[i] < march->dist[march->route_tot])
		{
			march->ants[i]++;
			j--;
		}
		i++;
	}
	i = 0;
	while (j--)
	{
		march->ants[i++]++;
		if (march->route_tot < i)
			i = 0;
	}
}