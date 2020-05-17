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
//where the pathfinder goes >...<
	if (!(route = ft_pathfind(map)))
	{
		free_map(&map);
		return(-1);
	}
	ft_putchar('\n');
	march_ant(route, ants);
	free_map(&map);
    printf("%s", "INPUT VALID\n");
	return (0);
}