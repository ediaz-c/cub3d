/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:41:13 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/09 02:41:37 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_caltulate_line(t_line *line, t_raysult *ray)
{
	line->line_height = abs((int)(WIN_H / ray->perp_wall_dist));
	line->draw_start = -line->line_height / 2 + WIN_H / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line->line_height / 2 + WIN_H / 2;
	if (line->draw_end >= WIN_H)
		line->draw_end = WIN_H - 1;
}
