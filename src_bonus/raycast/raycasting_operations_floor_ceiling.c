/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_operations_floor_ceiling.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:32:53 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/08 17:34:58 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	first_op(t_raysult *ray, t_player *p, int y)
{
	set_pos(&ray->ray_dir0, p->dir.x - p->plane.x, p->dir.y - p->plane.y);
		set_pos(&ray->ray_dir1, p->dir.x + p->plane.x, p->dir.y + p->plane.y);
		ray->screen_pos = y - WIN_H / 2;
		ray->pos_z = 0.5 * WIN_H;
		ray->row_dist = ray->pos_z / ray->screen_pos;
		ray->floor_step.x = ray->row_dist * (ray->ray_dir1.x - ray->ray_dir0.x) / WIN_W;
		ray->floor_step.y = ray->row_dist * (ray->ray_dir1.y - ray->ray_dir0.y) / WIN_W;
		ray->floor.x = p->pos.x + ray->row_dist * ray->ray_dir0.x;
		ray->floor.y = p->pos.y + ray->row_dist * ray->ray_dir0.y;
}

int	ft_dark_color(t_raysult *ray, t_player *p, int color)
{
	double	dist;
	double	max_dist;
	double	factor;
	int	r;
	int	g;
	int	b;
	
	max_dist = 15;
	dist = hypot(ray->floor.x - p->pos.x, ray->floor.y - p->pos.y);
	factor = 1.0 - dist / max_dist;
	if (factor < 0)
		factor = 0;
	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	return (r << 16) | (g << 8) | b;
}

void	ft_render_floor_and_ceiling(t_cube *cube, t_raysult *ray, t_player *p)
{
	int		x;
	int		y;
	int		floor_color;
	int		ceiling_color;

	y = -1;
	while (++y < WIN_H)
	{
		first_op(ray, p, y);
		x = -1;
		while (++x < WIN_W)
		{
			ray->cell.x = (int)(ray->floor.x);
			ray->cell.y = (int)(ray->floor.y);
			ray->tex.x = (int)(TEXTURE_WIDHT * (ray->floor.x - ray->cell.x)) & (TEXTURE_WIDHT - 1);
			ray->tex.y = (int)(TEXTURE_HEIGHT * (ray->floor.y - ray->cell.y)) & (TEXTURE_HEIGHT - 1);
			ray->floor.x += ray->floor_step.x;
			ray->floor.y += ray->floor_step.y;
			floor_color = cube->txt->floor.buffer[TEXTURE_WIDHT * ray->tex.y + ray->tex.x];
			ceiling_color = cube->txt->ceiling.buffer[TEXTURE_WIDHT * ray->tex.y + ray->tex.x];
			my_img_pixel_put(&cube->img, x, y, ft_dark_color(ray, p, floor_color));
			my_img_pixel_put(&cube->img, x, WIN_H - y - 1, ft_dark_color(ray, p, ceiling_color));
		}
	}
}
