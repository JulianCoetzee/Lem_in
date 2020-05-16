
#include "lemin.h"

//frees all items in array and then array pointer

void    free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        ft_strdel(&arr[i]);
        i++;
    }
    free(arr);
}

//frees saved rooms and subsequent connected t_room structs (links)

void    free_map(t_room **map)
{
    t_room  *room;
    t_room  *next;

    if (*map == NULL)
        return ;
    room = *map;
    while (room != NULL)
    {
        free_link_array((room->links));
        next = room->next;
        free(room->name);
        free(room);
        room = next;
    }
    *map = NULL;
}

void    free_link_array(t_room **links)
{
    if (!links)
        return ;
    free(links);
}

void    free_links(t_room *room)
{
    free(room->links);
    room->links = NULL;
}