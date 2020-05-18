/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   king_jul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:56:39 by giantewok         #+#    #+#             */
/*   Updated: 2020/05/18 11:22:22 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

static int route_num(char ***route)
{
	int i;

	i = 0;
	while (route[i])
		i++;
	return(i);    
}

static int room_num(char **route)
{
	int i;

	i = 0;
	while (route[i])
		i++;
	return (i - 1);
}

static int  *route_dist(char ***route, int t)
{
	int *dist;
	int i;
	
	i = 0;
	if (!(dist = (int*)ft_memalloc(sizeof(int) * (t + 1))))
		error_out(4);
	while (t > i)
	{
		dist[i] = room_num(route[i]);
		i++;
	}
	return (dist);
}

void           move_ant(char ***route, int i_ant)
{
	t_march *march;

	march = (t_march*)ft_memalloc(sizeof(t_march));
	march->ant_tot = i_ant;
	march->route_tot = route_num(route);
	march->dist = route_dist(route, march->route_tot);
	march->ants = (int*)ft_memalloc(sizeof(int) * (march->route_tot + 1));
	if (march->route_tot == 1 || i_ant == 1)
		sing_route(route[0], i_ant, march->dist[0]);
	else
	{
		if (!(march->route_tot = route_quan(i_ant, march->dist)))
			sing_route(route[0], i_ant, march->dist[0]);
		else
		{
			sep_ant(march);
			multi_route(route, march);
		}
	}
	free_int_array(&(march->ants));
	free_int_array(&(march->dist));
}