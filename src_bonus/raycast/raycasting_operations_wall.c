/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_operations_wall.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:25:34 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/15 13:46:40 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calculate_ray_and_dist(t_raysult *ray, t_player *p, int x)
{
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_dir.x = p->dir.x + p->plane.x * ray->camera_x;
	ray->ray_dir.y = p->dir.y + p->plane.y * ray->camera_x;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = HUGE_VALF;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = HUGE_VALF;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

void	ft_calculate_step(t_raysult *ray, t_player *p)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (p->pos.x - ray->mpos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->mpos.x + 1.0 - p->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (p->pos.y - ray->mpos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->mpos.y + 1.0 - p->pos.y) * ray->delta_dist.y;
	}
}

char	get_wall_tex(t_raysult *ray)
{
	char	wall_tex;

	if (ray->ray_dir.x < 0 && ray->side == 0)
		wall_tex = 'W';
	else if (ray->ray_dir.x > 0 && ray->side == 0)
		wall_tex = 'E';
	else if (ray->ray_dir.y < 0 && ray->side == 1)
		wall_tex = 'N';
	else
		wall_tex = 'S';
	return (wall_tex);
}

void	ft_dda(t_cube *cube, t_raysult *ray, t_line *line)
{
	while (ray->hit == 0)
	{
		ray->is_door = 0;
		if (cube->map[(int)ray->mpos.y][(int)ray->mpos.x] == 'd')
			ray->is_door = 1;
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->mpos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->mpos.y += ray->step.y;
			ray->side = 1;
		}
		line->wall_tex = get_wall_tex(ray);
		if (ft_check_hit_door(cube, ray) == 0)
			return ;
		if (ft_check_hit_wall(cube, ray) == 0)
			ray->hit = 1;
	}
}

void	ft_calculate_wall_dist(t_raysult *ray, t_cube *cube)
{
	if (ray->door == 0)
	{
		if (ray->side == EAST || ray->side == WEST)
			ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		else
			ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	}
	else
	{
		if (ray->side == 0)
			ray->perp_wall_dist = fabs((ray->mpos.x - cube->p->pos.x
						+ (1 - ray->step.x) - 0.5) / ray->ray_dir.x);
		else
			ray->perp_wall_dist = fabs((ray->mpos.y - cube->p->pos.y
						+ (1 - ray->step.y) - 0.5) / ray->ray_dir.y);
	}
}
