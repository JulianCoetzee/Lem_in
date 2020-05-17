
#include "lemin.h"

static void		st_put_linklen(t_room *node, int len)
{
	t_room **temp;

	temp = node->links;
	if (temp)
	{
		while (*temp)
		{
			if ((*temp)->len == -1)
			{
				(*temp)->len = len + 1;
				(*temp)->prev = node;
			}
			temp++;
		}
	}
}

/*
** Fills in all the (*links)->len and (*links)->prev
*/

char			**ft_path(t_room *room)
{
	char	**path;
	int		len;
	t_room	*temp;

	len = 0;
	temp = room;
	while (temp && ++len)
		temp = temp->prev;
	if (!(path = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	path[len] = NULL;
	while (len)
	{
		path[--len] = room->name;
		room = room->prev;
	}
	return (path);
}

char			**ft_excl_path(t_room *room)
{
	char	**path;
	int		len;
	t_room	*temp;

	len = 0;
	temp = room;
	while (temp && ++len)
		temp = temp->prev;
	if (!(path = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	path[len] = NULL;
	if (room->prev->start == 1)
		free_links(room->prev);
	while (len)
	{
		if (room->start == 0)
			free_links(room);
		path[--len] = room->name;
		room = room->prev;
	}
	return (path);
}

static int		ft_run_put_linklen(t_room **temp, int len)
{
	st_put_linklen(*temp, len);
	*temp = (*temp)->next;
	return (0);
}

/*
** Returns the path like a strsplit of the roomnames.
**
** excl_path removes the links of the middle rooms making them dead end
** and thus excluded from future path finding.
**
** path needs freeing but "dont free the roomnames"
** (the roomnames are just pointing at whats in each node)
** (so those can be freed when the rooms are freed)
*/

char			**ft_minpath(t_room *rooms)
{
	t_room	*temp;
	int		len;
	int		nopath;

	temp = rooms;
	len = 0;
	nopath = 0;
	while (!nopath)
	{
		if (temp == rooms)
			nopath = 1;
		while (temp && temp->len != len)
			temp = temp->next;
		if (len == 0 && temp)
			temp->prev = NULL;
		if (temp && temp->start != -1)
			nopath = ft_run_put_linklen(&temp, len);
		else if (temp)
			return (ft_excl_path(temp));
		if (!temp && ++len)
			temp = rooms;
	}
	return (NULL);
}

/*
** Finds the minpath, will inf loop if exit cant connect to start (for now)
*/
