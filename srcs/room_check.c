/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:59:29 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:00:01 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// ft_rooms checks arrays for start or end rooms
// checks coordinates
// after clearing checks, saves rooms from read data and frees read

int ft_rooms(t_room **map, char **arr, int *start, int *end)
{
    t_room  *room;

    room = add_room(map);
    if (*start == 1 || *end == 1)
        command_check(&room, start, end);
    if (!check_co_ords(arr))
    {
        free_array(arr);
        del_room(map);
        return (0);
    }
    room->name = ft_strdup(arr[0]);
    room->x = ft_atoi(arr[1]);
    room->y = ft_atoi(arr[2]);
    room->next = NULL;
    room->links = NULL;
    free_array(arr);
    return (1);
}

//command_check checks commands 
//invalidates additional commands after 1 "##start" and 1 "##end"

void    command_check(t_room **room, int *start, int *end)
{
    if (*start == 1)
    {
        (*room)->start = 1;
        (*room)->len = 0;
        *start = -1;
    }
    else if (*end == 1)
    {
        (*room)->start = -1;
        *end = -1;
    }
    else
        (*room)->start = 0;    
}

// checks coordinates for digits only

int     check_co_ords(char **arr)
{
    int i;
    int j;

    i = 1;
    while (arr[i] != NULL)
    {
        j = 0;
        while (arr[i][j] != '\0')
        {
            if (!ft_isdigit(arr[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    if (!ft_can_atoi(arr[1]) || !ft_can_atoi(arr[2]))
        return (0);
    return (1);
}