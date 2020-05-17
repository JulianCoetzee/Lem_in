/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:01:58 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:01:59 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//return (1) if duplicate to reader function 
//duplicate_name and duplicate_coordinates must return false (0)

int is_duplicate(t_room **map)
{
    if (duplicate_name(map) == 1 || duplicate_coordinates(map) == 1)
        return (1);
    else
        return (0);
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