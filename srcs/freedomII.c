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