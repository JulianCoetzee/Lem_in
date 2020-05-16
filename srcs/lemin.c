#include "lemin.h"

int		main(int argc, char **argv)
{
	int		ants;
	t_room	*map;

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
	ft_putchar('\n');
	free_map(&map);
    printf("%s", "INPUT VALID\n");
	return (0);
}