/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:24:15 by erick             #+#    #+#             */
/*   Updated: 2024/01/09 20:28:40 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void	cpy_pos(t_pos *pos1, t_pos *pos2)
{
	pos2->x = pos1->x;
	pos2->y = pos2->y;
}

void	set_pos_int(t_pos_int *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

void	cpy_pos_int(t_pos_int *pos1, t_pos_int *pos2)
{
	pos2->x = pos1->x;
	pos2->y = pos2->y;
}
