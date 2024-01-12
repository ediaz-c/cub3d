/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:59:10 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/10 00:44:00 by ediaz--c         ###   ########.fr       */
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

t_img	*ft_get_orientation(t_line *line, t_cube *cube, t_raysult *ray)
{
	t_img	*texture;

	texture = NULL;
	(void)ray;
	if (ray->is_door == 1 && ray->door == 0)
		texture = &cube->txt->door_wall;
	else if (ray->is_door == 1 && ray->door == 1)
		texture = &cube->txt->door;
	else if (line->wall_tex == 'N')
		texture = &cube->txt->no;
	else if (line->wall_tex == 'S')
		texture = &cube->txt->so;
	else if (line->wall_tex == 'E')
		texture = &cube->txt->ea;
	else if (line->wall_tex == 'W')
		texture = &cube->txt->we;
	return (texture);
}

void	ft_calculate_texture_x(t_cube *cube, t_line *line, t_raysult *ray)
{
    t_player	*p;

    p = cube->p;
    if (ray->side == 0)
        ray->wall_x = p->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
    else
        ray->wall_x = p->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
    ray->wall_x -= floor(ray->wall_x);
    ray->texture = ft_get_orientation(line, cube, ray);
    line->tex_x = (int)(ray->wall_x * (double)ray->texture->width);
    if (ray->side == 0 && ray->ray_dir.x > 0)
        line->tex_x = ray->texture->width - line->tex_x - 1;
    if (ray->side == 1 && ray->ray_dir.y < 0)
        line->tex_x = ray->texture->width - line->tex_x - 1;
}

void	ft_draw_wall(t_cube *cube, t_raysult *ray, double *step, double *tex_pos)
{
	int		color;

	ray->line->tex_y = (int)(*tex_pos) & (ray->texture->height - 1);
	(*tex_pos) += (*step);
	color = ray->texture->buffer[ray->texture->height * ray->line->tex_y + ray->line->tex_x];
	color = ft_dark_color_wall(ray, color);
	my_img_pixel_put(&cube->img, ray->curent_col, ray->current_row, color);
}

void	ft_paint_pixels(t_cube *cube, t_line *line, t_raysult *ray, int x)
{
    double	step;
    double	tex_pos;
    int		y;

    step = 1.0 * ray->texture->height / line->line_height;
    tex_pos = (line->draw_start - WIN_H / 2 + line->line_height / 2) * step;
	y = line->draw_start;
    ray->line = line;
    while (y <= line->draw_end)
    {
        ray->curent_col = x;
        ray->current_row = y;
        ft_draw_wall(cube, ray, &step, &tex_pos);
        y++;
    }
}
