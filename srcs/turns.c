/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:57:06 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 18:59:55 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     turn_total(t_march *move_out)
{
    int i;
    int total;

    i = 0;
    total = (move_out->path_sizes[0] + move_out->ants[0]);
    while (move_out->path_sizes[++i])
        {
            if (move_out->path_sizes[i] + move_out->ants[i] > total)
                total = move_out->path_sizes[i] + move_out->ants[i];
        }
    return (total - 1);
}

void    turn_loop(t_march *move_out, t_move **moves)
{
    int j;

    j = 0;
    while (j <= move_out->route_total && move_out->i < move_out->ant_total + move_out->path_size_sum)
    {
        ant_turn(moves[j], (move_out->ants[j]-- > 0) ? move_out->i++ : 0,
                 move_out->path_sizes[j]);
        // if (move_out->ants[j]-- > 0)
        //     ant_turn(moves[j], i++, move_out->path_sizes[j]);
        // else
        //     ant_turn(moves[j], 0, move_out->path_sizes[j]);
        j++;
    }
}

int     multi_move_check(t_move *move, int path_size)
{
    if (move && path_size)
        return (1);
    else
        return (0);
}

void    out_loop(t_march *move_out, t_move **moves)
{
    int i;

    i = 0;
    while (i <= move_out->route_total)
    {
        move_output(moves[i], move_out->path_sizes[i]);
        i++;
        if (multi_move_check(moves[i], move_out->path_sizes[i]))
            ft_putchar(' ');
        else
            i++;
    }
}