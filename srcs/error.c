/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:01:47 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 19:01:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error_out(int errtype)
{
	if (errtype == 1)
		ft_putendl_fd("ERROR INPUT INVALID", 2);
	else if (errtype == 2)
		ft_putendl_fd("ERROR PATH INVALID", 2);
	else if (errtype == 3)
		ft_putendl_fd("ERROR ANTS INVALID", 2);
	else if (errtype == 4)
		ft_putendl_fd("ERROR MALLOC FAILED", 2);
	else if (errtype == 5)
		ft_putendl_fd("ERROR DUPLICATE ROOM", 2);
	else if (errtype == 6)
		ft_putendl_fd("ERROR LINKING FAILED", 2);
	else if (errtype == 8)
		ft_putendl_fd("ERROR WUT", 2);
	exit(1);
}