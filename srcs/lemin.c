/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:56:50 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:58:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	int		ants;
	t_room	*map;
	char	***route;

	(void)argv;
	(void)argc;
	map = NULL;
	ants = get_ants();
	ft_putchar('\n');
	get_map(&map);
	if (!ants)
	{
		free_map(&map);
		return (0);
	}
	if (!(route = paths_found(map)))
	{
		free_map(&map);
		return (0);
	}
	move_ant(route, ants);
	free_map(&map);
	free_route(&route);
	return (0);
}