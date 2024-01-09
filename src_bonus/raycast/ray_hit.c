/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:34:48 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/10 00:14:33 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_hit_wall(t_cube *cube, t_raysult *ray)
{
	if (cube->map[(int)ray->mpos.y][(int)ray->mpos.x] == '1')
		return (0);
	return (1);
}

int	ft_check_hit_door(t_cube *cube, t_raysult *ray)
{
	if (cube->map[(int)ray->mpos.y][(int)ray->mpos.x] == 'D')
	{
		ray->is_door = 1;
		if (ray->side == NORTH || ray->side == SOUTH)
		{
			if (ray->side_dist.x >= ray->side_dist.y - (ray->delta_dist.y / 2))
			{
				ray->side_dist.y += ray->delta_dist.y;
				ray->mpos.y += ray->step.y;
				ray->side = 1;
				ray->door = 1;
			}
			else
			{
				ray->side_dist.x += ray->delta_dist.x;
				ray->mpos.x += ray->step.x;
				ray->side = 0;
				ray->door = 0;
			}
		}
		else
		{
			if (ray->side_dist.x - (ray->delta_dist.x / 2)  >= ray->side_dist.y)
			{
				ray->side_dist.y += ray->delta_dist.y;
				ray->mpos.y += ray->step.y;
				ray->side = 1;
				ray->door = 0;
			}
			else
			{
				ray->side_dist.x += ray->delta_dist.x;
				ray->mpos.x += ray->step.x;
				ray->side = 0;
				ray->door = 1;
			}
		}
		if (ray->side == 0)
			ray->perp_wall_dist = fabs((ray->mpos.x - cube->p->pos.x + (1 - ray->step.x) - 0.5) / ray->ray_dir.x);
		else
			ray->perp_wall_dist = fabs((ray->mpos.y - cube->p->pos.y + (1 - ray->step.y) - 0.5) / ray->ray_dir.y);
		return (0);
	}
	return (1);
}
