/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:43:24 by erick             #+#    #+#             */
/*   Updated: 2024/01/09 20:16:56 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
*	First operation of raycasting
*	1. Calculate camera_x
*	2. Calculate ray_dir and delta_dist
*	3. Calculate step and side_dist
*/
static void	ft_first_op(t_player *p, t_raysult *ray, int x)
{
	ray->mpos.x = (int)p->pos.x;
	ray->mpos.y = (int)p->pos.y;
	ray->hit = 0;
	ray->door = 0;
	ft_calculate_ray_and_dist(ray, p, x);
	ft_calculate_step(ray, p);
}

void	set_mid_hit(t_cube *cube, t_raysult *ray, t_line *line)
{
	if (line->wall_tex == 'W')
		set_pos(&cube->door_handler, ray->mpos.x + 1, ray->mpos.y);
	else if (line->wall_tex == 'E')
		set_pos(&cube->door_handler, ray->mpos.x - 1, ray->mpos.y);
	else if (line->wall_tex == 'N')
		set_pos(&cube->door_handler, ray->mpos.x, ray->mpos.y + 1);
	else if (line->wall_tex == 'S')
		set_pos(&cube->door_handler, ray->mpos.x, ray->mpos.y - 1);
}

void	raycasting(t_cube *cube)
{
	int			x;
	t_raysult	ray;
	t_line		line;
	t_player	*player;

	x = -1;
	player = cube->p;
	mlx_clear_window(cube->mlx->mlx, cube->mlx->win);
	ft_render_floor_and_ceiling(cube, &ray, player);
	set_pos(&cube->door_handler, -1, -1);
	while (++x < WIN_W)
	{
		ft_first_op(player, &ray, x);
		line.wall_tex = ft_dda(cube, &ray);
		ft_calculate_wall_dist(&ray, cube);
		ft_caltulate_line(&line, &ray);
		ft_calculate_texture_x(cube, &line, &ray);
		ft_paint_pixels(cube, &line, &ray, x);
		if (x == WIN_W / 2)
		{
			if (ray.is_door)
				set_mid_hit(cube, &ray, &line);
			else
				set_pos(&cube->door_handler, -1, -1);
		}
	}
}
