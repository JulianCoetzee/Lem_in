/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:58:02 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 18:59:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    move_output(t_move *move, int path_size)
{
    while (path_size--)
    {
        if (move[path_size].ant)
        {
            ft_putchar('L');
            ft_putnbr(move[path_size].ant);
            ft_putchar('-');
            ft_putstr(move[path_size].room);
        }            
    }
}