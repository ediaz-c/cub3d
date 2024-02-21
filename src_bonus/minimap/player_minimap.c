/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:39:59 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/02/21 10:49:33 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_circle(t_minimap *mini, int x, int y)
{
	int	xc;
	int	yc;
	int	i;

	xc = SIZE_MINI / 2;
	yc = SIZE_MINI / 2;
	i = -x;
	while (i <= x)
	{
		mini->buffer[(xc + i) * SIZE_MINI + (yc + y)] = 0x00FF0000;
		mini->buffer[(xc + i) * SIZE_MINI + (yc - y)] = 0x00FF0000;
		i++;
	}
	i = -y;
	while (i <= y)
	{
		mini->buffer[(xc + x) * SIZE_MINI + (yc + i)] = 0x00FF0000;
		mini->buffer[(xc - x) * SIZE_MINI + (yc + i)] = 0x00FF0000;
		i++;
	}
}

void	draw_player(t_minimap *mini, int radius)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	draw_circle(mini, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		draw_circle(mini, x, y);
	}
}

void	calculate_end_points(t_cube *cube, int line_length,
	t_line_params *params)
{
	double	dir_length;

	dir_length = sqrt(cube->p->dir.x * cube->p->dir.x
			+ cube->p->dir.y * cube->p->dir.y);
	params->x = SIZE_MINI / 2;
	params->y = SIZE_MINI / 2;
	params->end_x = SIZE_MINI / 2 + (cube->p->dir.x / dir_length) * line_length;
	params->end_y = SIZE_MINI / 2 + (cube->p->dir.y / dir_length) * line_length;
	params->dx = abs(params->end_x - params->x);
	params->dy = abs(params->end_y - params->y);
	if (params->x < params->end_x)
		params->step_x = 1;
	else
		params->step_x = -1;
	if (params->y < params->end_y)
		params->step_y = 1;
	else
		params->step_y = -1;
	if (params->dx > params->dy)
		params->error = params->dx / 2;
	else
		params->error = -params->dy / 2;
}

void	draw_line(t_minimap *mini, t_line_params *params, int line_length)
{
	int	iterations;
	int	e2;

	iterations = -1;
	while (++iterations < line_length)
	{
		if (params->x >= 0 && params->x < SIZE_MINI
			&& params->y >= 0 && params->y < SIZE_MINI)
		{
			mini->buffer[params->y * SIZE_MINI + params->x] = 0x00FF0000;
		}
		if (params->x == params->end_x && params->y == params->end_y)
			break ;
		e2 = params->error;
		if (e2 > -params->dx)
		{
			params->error -= params->dy;
			params->x += params->step_x;
		}
		if (e2 < params->dy)
		{
			params->error += params->dx;
			params->y += params->step_y;
		}
	}
}

void	add_mini_player(t_cube *cube, t_minimap *mini)
{
	int				scale;
	int				line_length;
	t_line_params	params;

	scale = 3;
	line_length = 20;
	ft_draw_fov(cube, mini);
	draw_player(mini, scale);
	calculate_end_points(cube, line_length, &params);
	draw_line(mini, &params, line_length);
}
