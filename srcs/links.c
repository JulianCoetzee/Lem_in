/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:51 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:01:02 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// adds links to enlarged array for given room (after copying existing links)

void    add_links(t_room ***tmp_links, t_room ***set_links, t_room **door, int array_size)
{
    int i;

    i = 0;
    while (i < array_size)
    {
        (*set_links)[i] = (*tmp_links)[i];
        i++;
    }
    (*set_links)[i] = *door;
    i++;
    (*set_links)[i] = NULL;
}

//  link second room (door) in link_array to first (room)

static int  link_links(t_room **door, t_room **room)
{
    int     array_size;
    t_room  **tmp_links;
    t_room  **set_links;

    array_size = 0;
    tmp_links = (*door)->links;
    if (tmp_links == NULL)
    {
        if (!(tmp_links = (t_room**)malloc(sizeof(t_room*) * 2)))
            return (0);
        tmp_links[0] = *room;
        tmp_links[1] = NULL;
        (*door)->links = tmp_links;
        return (1);
    }
    while (tmp_links[array_size] != NULL)
        array_size++;
    if (!(set_links = (t_room**)malloc(sizeof(t_room*) * (array_size + 2))))
        return (0);
    add_links(&tmp_links, &set_links, room, array_size);
    free(tmp_links);
    (*door)->links = set_links;
    return (1);
}

//expands given room->links array to accomodate new link and adds using add_links
// stores current link array and mallocs for larger array

int link_array(t_room **room, t_room **door)
{
    int     array_size;
    t_room  **tmp_links;
    t_room  **set_links;

    array_size = 0;
    tmp_links = (*room)->links;
    if (tmp_links == NULL)
    {
        if (!(tmp_links = (t_room**)malloc(sizeof(t_room*) * 2)))
            return (0);
        tmp_links[0] = *door;
        tmp_links[1] = NULL;
        (*room)->links = tmp_links;
        return (link_links(door, room));
    }
    while (tmp_links[array_size] != NULL)
        array_size++;
    if (!(set_links = (t_room**)malloc(sizeof(t_room*) * (array_size + 2))))
        return (0);
    add_links(&tmp_links, &set_links, door, array_size);
    free(tmp_links);
    (*room)->links = set_links;
    return (link_links(door, room));
}