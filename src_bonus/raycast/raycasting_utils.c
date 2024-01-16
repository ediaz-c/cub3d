/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:40:58 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/14 18:13:36 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_is_door(t_cube *cube, t_raysult *ray)
{
	ray->is_door = 0;
	if (cube->map[(int)ray->mpos.y][(int)ray->mpos.x] == 'D')
		ray->is_door = 1;
}

int	ft_dark_color_wall(t_raysult *ray, int color)
{
	double	max_dist;
	double	factor;
	int		r;
	int		g;
	int		b;

	max_dist = 15;
	factor = 1.0 - ray->perp_wall_dist / max_dist;
	if (factor < 0)
		factor = 0;
	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	return ((r << 16) | (g << 8) | b);
}
