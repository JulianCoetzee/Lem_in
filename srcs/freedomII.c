#include "lemin.h"

void    free_move(t_move **move)
{
	free(*move);
	*move = NULL;
}

void    free_move_array(t_move ***moves)
{
	int i;

	i = 0;
	while ((*moves)[i])
		free_move(&(*moves)[i++]);
	free(*moves);
	*moves = NULL;
}

void    free_march_array(t_march *march)
{
	free(march);
	march = NULL;
}

void    free_int_array(int **arr)
{
    free(*arr);
    *arr = NULL;
}

void	free_route(char ****route_loc)
{
	int		i;
	char	***routes;

	routes = *route_loc;
	i = 0;
	while (routes[i])
	{
		free(routes[i]);
		i++;
	}
	free(routes);
	routes = NULL;
}