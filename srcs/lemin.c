/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:56:50 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 18:56:51 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	int		ants;
	char 	***paths;
	t_room	*map;
	// t_move	*move;

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
	// ft_putchar('\n');
	// free_map(&map);
    // printf("%s", "INPUT VALID\n");
	if (!(paths = ft_pathfind(map)))
	{
		free_map(&map);
		return (0);
	}
	// ft_putchar('\n');
	ant_march(paths, ants);
	free_map(&map);
	free_paths(&paths);
	return (0);
}