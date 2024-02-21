/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:09:17 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/21 11:12:57 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_fov_line_conditions(t_minimap *mini, t_line_params *params)
{
	if (params->y >= mini->height || params->x >= mini->width \
	|| params->y == 0 || params->x == 0)
		return (1);
	if (mini->buffer[params->y * SIZE_MINI + params->x] != MINI_FLOOR && \
	mini->buffer[params->y * SIZE_MINI + params->x] != 0x00FF0000 && \
	mini->buffer[params->y * SIZE_MINI + params->x] != 0x00FFD790 && \
	mini->buffer[params->y * SIZE_MINI + params->x] != FOV_COLOR)
		return (1);
	return (0);
}

void	ft_draw_fov_line(t_minimap *mini, t_line_params *params)
{
	int	e2;

	while (1)
	{
		if (ft_fov_line_conditions(mini, params) == 1)
			break ;
		if (params->x >= 0 && params->x < SIZE_MINI \
		&& params->y >= 0 && params->y < SIZE_MINI)
			mini->buffer[params->y * SIZE_MINI + params->x] = FOV_COLOR;
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

void	ft_vision_ray(t_pos dir, t_line_params *params)
{
	double	dir_length;

	dir_length = sqrt(dir.x * dir.x + dir.y * dir.y);
	params->x = SIZE_MINI / 2;
	params->y = SIZE_MINI / 2;
	params->end_x = SIZE_MINI / 2 + (dir.x / dir_length) * 20;
	params->end_y = SIZE_MINI / 2 + (dir.y / dir_length) * 20;
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

void	ft_fov_loop(t_cube *cube, t_minimap *mini, float increment)
{
	t_line_params	params;
	t_pos			p;

	p.x = cube->p->dir.x * cos(increment) - cube->p->dir.y * sin(increment);
	p.y = cube->p->dir.x * sin(increment) + cube->p->dir.y * cos(increment);
	ft_vision_ray(p, &params);
	ft_draw_fov_line(mini, &params);
}

void	ft_draw_fov(t_cube *cube, t_minimap *mini)
{
	float			increment;
	int				i;

	increment = 0.0174533;
	i = 0;
	ft_fov_loop(cube, mini, (i * increment));
	while (++i <= 40)
	{
		ft_fov_loop(cube, mini, (i * increment));
		ft_fov_loop(cube, mini, ((-1) * i * increment));
	}
}
