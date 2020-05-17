
#include "lemin.h"

/*
** Maxpaths will never be greater than start->links or exit->links
** (could be smaller but its a good starting point to malloc paths)
** returns (0) if there isnt a start and end (uses the first of each otherwise
*/

int		st_maxpaths(t_room *rooms)
{
	int num;
	int i;
	int fnd;

	num = 0;
	while (rooms && rooms->start != 1 && rooms->start != -1)
		rooms = rooms->next;
	fnd = rooms->start;
	i = 0;
	if (!rooms)
		return (0);
	while (rooms->links[i])
		i++;
	num = i;
	rooms = rooms->next;
	while (rooms && rooms->start != fnd * -1)
		rooms = rooms->next;
	i = 0;
	if (!rooms)
		return (0);
	while (rooms->links[i])
		i++;
	if (i < num)
		num = i;
	return (num);
}

/*
** st_findpaths finds the best set of paths, it finds the shortest first
** then using that ("will later") attempts to find better multipaths.
**
** "currently only does the shortest possible path."
*/

void	st_pathclear(t_room *rooms)
{
	while (rooms)
	{
		if (rooms->len)
			rooms->len = -1;
		rooms = rooms->next;
	}
}

void	st_findpaths(char ***paths, t_room *rooms)
{
	int	i;

	i = 0;
	paths[0] = ft_minpath(rooms);
	while (paths[i++])
	{
		st_pathclear(rooms);
		paths[i] = ft_minpath(rooms);
	}
	if (!(paths[0]))
	{
		free(paths);
		error_out(2);
	}
}

/*
** Findpaths returns a 3D array of paths->each_path->roomnames
**
** do maxpaths = st_maxpaths(rooms); when more paths are used
*/

char	***ft_pathfind(t_room *rooms)
{
	char	***paths;
	int		maxpaths;

	if (!(maxpaths = st_maxpaths(rooms)))
	{
		error_out(2);
		return (NULL);
	}
	if (!(paths = (char ***)malloc(sizeof(char **) * (maxpaths + 1))))
	{
		error_out(4);
		return (NULL);
	}
	st_findpaths(paths, rooms);
	return (paths);
}

/*
// ** Prints each path on a new line, for testing
// */

// void	ft_printpath(char ***paths)
// {
// 	int i;
// 	int k;

// 	k = 0;
// 	while (paths[k])
// 	{
// 		i = 0;
// 		printf("path %d\n", k);
// 		while (paths[k][i] && paths[k][i + 1])
// 			printf("%s to ", paths[k][i++]);
// 		printf("%s", paths[k][i]);
// 		printf("\n");
// 		k++;
// 	}
// }
