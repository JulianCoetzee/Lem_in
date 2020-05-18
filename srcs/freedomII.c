/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedomII.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:04 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 18:57:05 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    free_move(t_move **move)
{
	ft_memdel((void **)move);
}

void    free_move_array(t_move ***moves)
{
	int i;

	i = 0;
	while ((*moves)[i])
	{
		free_move(&(*moves)[i]);
		i++;
	}
	free(*moves);
	*moves = NULL;
}

void    free_paths(char ****paths_pointer)
{
	int i;
	char ***paths;

	paths = *paths_pointer;
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	paths = NULL;
}