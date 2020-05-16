
#include "lemin.h"

//mallocs for t_room and returns pointer for it

t_room  *new_room(void)
{
    t_room  *new;

    new = (t_room*)malloc(sizeof(t_room));
    new->len = -1;
    new->links = NULL;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

// takes valid pointer and adds to saved rooms
// if pointer is empty uses new_room, 
// if not, iterates to newest room and uses new_room and return pointer

t_room  *add_room(t_room **map)
{
    t_room  *room;

    if (*map == NULL)
    {
        *map = new_room();
        room = *map;
    }
    else
    {
        room = *map;
        while (room->next != NULL)
            room = room->next;
        room->next = new_room();
        room->next->prev = room;
        room = room->next;
    }
    return (room);
}

void    del_room(t_room **map)
{
    t_room  *room;
    t_room  *second;

    if (*map == NULL)     
        return ;
    while (room != NULL)
    {
        second = room->next;
        free(room);
        room = second;
    }
    *map = NULL;
}