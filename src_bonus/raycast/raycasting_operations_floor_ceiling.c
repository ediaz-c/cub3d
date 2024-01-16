/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_operations_floor_ceiling.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:32:53 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/14 19:18:54 by ediaz--c         ###   ########.fr       */
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
	ray->floor_step.x = ray->row_dist
		* (ray->ray_dir1.x - ray->ray_dir0.x) / WIN_W;
	ray->floor_step.y = ray->row_dist
		* (ray->ray_dir1.y - ray->ray_dir0.y) / WIN_W;
	ray->floor.x = p->pos.x + ray->row_dist * ray->ray_dir0.x;
	ray->floor.y = p->pos.y + ray->row_dist * ray->ray_dir0.y;
}

int	ft_dark_color(t_raysult *ray, t_player *p, int color)
{
	t_dark_color	dark;

	dark.max_dist = 15;
	dark.dist = hypot(ray->floor.x - p->pos.x, ray->floor.y - p->pos.y);
	dark.factor = 1.0 - dark.dist / dark.max_dist;
	if (dark.factor < 0)
		dark.factor = 0;
	dark.r = ((color >> 16) & 0xFF) * dark.factor;
	dark.g = ((color >> 8) & 0xFF) * dark.factor;
	dark.b = (color & 0xFF) * dark.factor;
	return ((dark.r << 16) | (dark.g << 8) | dark.b);
}

void	ft_render_op(t_raysult *ray, t_render_floor_and_ceiling *render)
{
	set_pos_int(&ray->cell, (int)ray->floor.x, (int)ray->floor.y);
	set_pos_int(&ray->tex,
		(int)(TEXTURE_WIDHT * (ray->floor.x - ray->cell.x))
		& (TEXTURE_WIDHT - 1),
		(int)(TEXTURE_HEIGHT * (ray->floor.y - ray->cell.y))
		& (TEXTURE_HEIGHT - 1));
	set_pos(&ray->floor, ray->floor.x + ray->floor_step.x,
		ray->floor.y + ray->floor_step.y);
	render->f_index = TEXTURE_WIDHT * ray->tex.y + ray->tex.x;
	render->c_index = TEXTURE_WIDHT * ray->tex.y + ray->tex.x;
	render->floor_color = render->floor_buffer[render->f_index];
	render->ceiling_color = render->ceiling_buffer[render->c_index];
}

void	ft_render_floor_and_ceiling(t_cube *cube, t_raysult *ray, t_player *p)
{
	t_render_floor_and_ceiling	render;

	render.y = (WIN_H / 2) - 1;
	render.floor_buffer = cube->txt->floor.buffer;
	render.ceiling_buffer = cube->txt->ceiling.buffer;
	while (++render.y < WIN_H)
	{
		first_op(ray, p, render.y);
		render.x = -1;
		while (++render.x < WIN_W)
		{
			ft_render_op(ray, &render);
			my_img_pixel_put(&cube->img, render.x, render.y,
				ft_dark_color(ray, p, render.floor_color));
			my_img_pixel_put(&cube->img, render.x, WIN_H - render.y - 1,
				ft_dark_color(ray, p, render.ceiling_color));
		}
	}
}
