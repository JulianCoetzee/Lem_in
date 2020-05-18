/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:13 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:00:08 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	path_count(char ***routes)
{
	int i;

	i = 0;
	while (routes[i])
		i++;
	return (i);
}

int	path_size(char **path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	return (i - 1);
}

int	*path_sizes(char ***routes, int route_total)
{
	int	*path_sizes;
	int	i;

	i = 0;
	if (!(path_sizes = (int*)ft_memalloc(sizeof(int) * (route_total + 1))))
		ft_putstr("couldn't malloc for len\n");
	while (i < route_total)
	{
		path_sizes[i] = path_size(routes[i]);
		i++;
	}
	return (path_sizes);
}

int path_size_sum(int *path_sizes)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (path_sizes[i])
	{
		sum = sum + path_sizes[i];
		i++;
	}
	return (sum);
}

int ant_routes_used(int ant_total, int *path_sizes)
{
	int i;
	int routes;

	i = 1;
	routes = 0;
	if ((ant_total - i) + path_sizes[0] >= i + path_sizes[1])
	{
		while ((ant_total - i) + path_sizes[0] >= i + path_sizes[1])
			i++;
		routes++;
	}
	if (path_sizes[2])
		routes = routes + ant_routes_used(i - 1, path_sizes + 1);
	return (routes);
}