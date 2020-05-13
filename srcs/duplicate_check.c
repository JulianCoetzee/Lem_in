#include "lemin.h"

//return (1) if duplicate to reader function 
//duplicate_name and duplicate_coordinates must return false (0)

int is_duplicate(t_room **map)
{
    if (!duplicate_name(map) || !duplicate_coordinates(map))
        return (0);
    else
        return (1);
}

int duplicate_name(t_room **map)
{
    t_room  *room;
    t_room  *next;

    room = *map;
    while (room != NULL)
    {
        next = room->next;
        while (next != NULL)
        {
            if (!strcmp(room->name, next->name))
                return (1);
            next = next->next;
        }
        room = room->next;
    }
    return (0);
}

int duplicate_coordinates(t_room **map)
{
    t_room  *room;
    t_room  *next;

    room = *map;
    while (room != NULL)
    {
        next = room->next;
        while (next != NULL)
        {
            if (room->x == next->x && room->y == next->y)
                return (1);
            next = next->next;
        }
        room = room->next;
    }
    return (0);
}