
#include "lemin.h"

//checks for valid link format before analyzing with subsequent functions ( links.c)
//via link_split

int ft_links(t_room **map, char *line)
{
    if (line[0] == 'L')
        return (0);
    else if (ft_strchr(line, '-'))
    {
        if (!link_split(map, line))
        {
            free_map(map);
            ft_strdel(&line);
            error_out(6);
        }
    }
    else
        return (0);
    return (1);
}

// check link size (no multi-link) separates rooms (room to (next)door)
// if all valid, aaded to saved links via link _array, else error

int link_split(t_room **map, char *line)
{
    char    **split_line;
    int     i;
    t_room  *room;
    t_room  *door;

    split_line = ft_strsplit(line, '-');
    i = 0;
    room = *map;
    door = *map;
    while (split_line[i] != NULL)
        i++;
    if (i >= 3)
        return (0);
    while (room != NULL && ft_strcmp(split_line[0], room->name))
        room = room->next;
    while (door != NULL && ft_strcmp(split_line[1], door->name))
        door = door->next;
    free_array(split_line);
    if (room == NULL || door == NULL)
        return (0);
    if (!link_array(&room, &door))
        return (0);
    return (1);
}