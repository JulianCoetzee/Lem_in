#include "lemin.h"

// static void			create_room(t_room **room)
// {
// 	if (!(*room = (t_room *)malloc(sizeof(t_room))))
// 		exit(1);
// 	(*room)->q_path = -1;
// 	(*room)->tmp_room = NULL;
// 	(*room)->start_r = NULL;
// 	(*room)->end_r = NULL;
// 	(*room)->path = NULL;
// 	(*room)->links = NULL;
// }

int		main(int argc, char **argv)
{
	int		ants;
	t_room	*map;

	(void)argc;
	(void)argv;
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
