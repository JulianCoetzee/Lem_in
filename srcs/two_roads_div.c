# include "lemin.h"

/*
** sep_check: splits the line read by spaces ' '
** if there are 3 elements its a room,
** if there is one its a link;
*/
int		sep_check(t_room **map, char *line, int *start, int *end)
{
	char		**arr;
	int			a_size;
	static int	link = 0;

	arr = ft_strsplit(line, ' ');
	a_size = 0;
	while (arr[a_size] != NULL)
		a_size++;
	if (a_size != 3 && a_size != 1)
	{
		free_array(arr);
		return (-1);
	}
	else if (a_size == 3)
	{
		if (ft_rooms(map, arr, start, end) == -1 || link == 1)
			return (-1);
	}
	else if (a_size == 1)
	{
		link = 1;
		free_array(arr);
		return (ft_links(map, line));
	}
	return (1);
}

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
		splits += route_num(i - 1, dist + 1);
	return (splits);
}

/*
**sep_ant: splits ants
**
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