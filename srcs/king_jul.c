# include "lemin.h"

static int route_num(char ***route)
{
	int i;

	i = 0;
	while (route[i])
		i++;
	return(i);    
}

static int room_num(char **route)
{
	int i;

	i = 0;
	while (route[i])
		i++;
	return (i - 1);
}

static int  *route_dist(char ***route, int t)
{
	int *l;
	int i;
	
	i = 0;
	if (!(l = (int*)ft_memalloc(sizeof(int) * (t + 1))))
		ft_putendl("Could not malloc route len.");
	while (t > i)
	{
		l[i] = room_num(route[i]);
		i++;
	}
	return(l);
}

void           march_ant(char ***route, int i_ant)
{
	t_march *march;

	march = (t_march*)ft_memalloc(sizeof(t_march));
	march->ant_tot = i_ant;
	march->route_tot = route_num(route);
	march->dist = route_dist(route, march->route_tot);
	march->ants = (int*)ft_memalloc(sizeof(int) * (march->route_tot + 1));
	if (march->route_tot == 1 || i_ant == 1)
		sing_route(route[0], i_ant, march->dist[0]);
	else
	{
		if (!(march->route_tot = route_quan(i_ant, march->dist)))
			sing_route(route[0], i_ant, march->dist[0]);
		else
		{
			sep_ant(march);
			multi_route(route, march);
		}
	}
	free_int_array(&(march->ants));
	free_int_array(&(march->dist));
	free_march_array(march);
}