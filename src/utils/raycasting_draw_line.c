/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:59:10 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/03 00:28:21 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_caltulate_line(t_cube *cube, t_line *line, t_raysult *ray)
{
    line->line_height = abs((int)(WIN_H / ray->perp_wall_dist));
    line->draw_start = -line->line_height / 2 + WIN_H / 2;
    if (line->draw_start < 0)
        line->draw_start = 0;
    line->draw_end = line->line_height / 2 + WIN_H / 2;
    if (line->draw_end >= WIN_H)
        line->draw_end = WIN_H - 1;
}

t_img	*ft_get_orientation(t_line *line, t_cube *cube)
{
	t_img	*texture;

	if (line->wall_tex == 'N')
		texture = &cube->txt->no;
	else if (line->wall_tex == 'S')
		texture = &cube->txt->so;
	else if (line->wall_tex == 'E')
		texture = &cube->txt->ea;
	else if (line->wall_tex == 'W')
		texture = &cube->txt->we;
	return (texture);
}

void	my_img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

		dst = (char *)img->buffer + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
}

void	ft_calculate_texture_x(t_cube *cube, t_line *line, t_raysult *ray, int x)
{
    t_player	*p;
    t_img		*texture;

    p = cube->p;
    if (ray->side == 0)
        ray->wall_x = p->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
    else
        ray->wall_x = p->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
    ray->wall_x -= floor(ray->wall_x);
    texture = ft_get_orientation(line, cube);
    line->tex_x = (int)(ray->wall_x * (double)texture->width);
    if (ray->side == 0 && ray->ray_dir.x > 0)
        line->tex_x = texture->width - line->tex_x - 1;
    if (ray->side == 1 && ray->ray_dir.y < 0)
        line->tex_x = texture->width - line->tex_x - 1;
}

void	ft_draw_wall(t_cube *cube, t_raysult *ray, double *step, double *tex_pos)
{
	t_img	*texture;

	texture = ft_get_orientation(ray->line, cube);
	ray->line->tex_y = (int)(*tex_pos) & (texture->height - 1);
	(*tex_pos) += (*step);
	my_img_pixel_put(&cube->img, ray->curent_col, ray->current_row,
		texture->buffer[texture->height * ray->line->tex_y + ray->line->tex_x]);
}

void	ft_paint_pixels(t_cube *cube, t_line *line, t_raysult *ray, int x)
{
    double	step;
    double	tex_pos;
    int		y;
    t_img	*texture;

    texture = ft_get_orientation(line, cube);
    step = 1.0 * texture->height / line->line_height;
    tex_pos = (line->draw_start - WIN_H / 2 + line->line_height / 2) * step;
    y = -1;
    ray->line = line;
    while (++y < line->draw_start)
        my_img_pixel_put(&cube->img, x, y, cube->octal_c);
    while (y <= line->draw_end)
    {
        ray->curent_col = x;
        ray->current_row = y;
		// my_img_pixel_put(&cube->img, x, y, 0x00FF0000);
        ft_draw_wall(cube, ray, &step, &tex_pos);
        y++;
    }
    while (y < WIN_H)
        my_img_pixel_put(&cube->img, x, y++, cube->octal_f);
}