#include "lemin.h"

void	put_move(t_move *move, int dist)
{
	int	i;

	i = 0;
	while (dist--)
	{
		if (move[dist].ant)
		{
			if (i++)
				ft_putchar(' ');
			ft_putchar('L');
			ft_putnbr((move[dist]).ant);
			ft_putchar('-');
			ft_putstr((move[dist]).room);
		}
		if (dist == 0)
			return ;
	}
}

t_move	*make_move(char **route, int dist)
{
	int		i;
	t_move	*move;

	i = 0;
	move = (t_move*)ft_memalloc(sizeof(t_move) * dist + 1);
	while (i < dist)
	{
		(move[i]).room = route[i + 1];
		(move[i++]).ant = 0;
	}
	move[i].room = NULL;
	return (move);
}

void	ant_turn(t_move *move, int i, int dist)
{
	while (dist)
	{
		move[dist].ant = move[dist - 1].ant;
		dist--;
	}
	move[0].ant = i;
}

void	sing_route(char **route, int i_ant, int dist)
{
	t_move	*move;
	int		i;

	i = 1;
	move = make_move(route, dist);
	while (i < i_ant + dist)
	{
		ant_turn(move, (i <= i_ant) ? i : 0, dist);
		put_move(move, dist);
		ft_putchar('\n');
		i++;
	}
	free_move(&move);
}