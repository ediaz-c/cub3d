/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:27:13 by erick             #+#    #+#             */
/*   Updated: 2023/10/23 17:03:14 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	ft_abs(double nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_init_dda(t_dda *dda, t_cube *cube)
{
	dda->win_width = cube->win_width;
	dda->win_height = cube->win_height;
	dda->pos_x = cube->p->x;
	dda->pos_y = cube->p->y;
	dda->dir_x = cube->p->dir_x;
	dda->dir_y = cube->p->dir_y;
	dda->plane_x = cube->p->plane_x;
	dda->plane_y = cube->p->plane_y;
	dda->map = cube->map;
}

void	ft_first_op(t_dda *dda, int x)
{
	dda->camerax = 2 * x / (double)dda->win_width - 1;
	dda->raydirx = dda->dir_x + dda->plane_x * dda->camerax;
	dda->raydiry = dda->dir_y + dda->plane_y * dda->camerax;
	dda->map_x = (int)dda->pos_x;
	dda->map_y = (int)dda->pos_y;
	dda->ddist_x = (dda->raydirx == 0) ? 1e30 : ft_abs(1/dda->raydirx);
	dda->ddist_y = (dda->raydiry == 0) ? 1e30 : ft_abs(1/dda->raydiry);
	dda->hit = 0;
}

void	ft_calculate_side_dist(t_dda *dda)
{
	if (dda->raydirx < 0)
	{
		dda->step_x = -1;
		dda->sdist_x = (dda->pos_x - dda->map_x) * dda->ddist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sdist_x = (dda->map_x + 1.0 - dda->pos_x) * dda->ddist_x;
	}
	if (dda->raydiry < 0)
	{
		dda->step_y = -1;
		dda->sdist_y = (dda->pos_y - dda->map_y) * dda->ddist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sdist_y = (dda->map_y + 1.0 - dda->pos_y) * dda->ddist_y;
	}
}

void	ft_calculate_dda(t_dda *dda, char **map)
{
	while (dda->hit == 0)
	{
		if (dda->sdist_x < dda->sdist_y)
		{
			dda->sdist_x += dda->ddist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sdist_y += dda->ddist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (map[dda->map_y][dda->map_x] > 0)
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perpWallDist = (dda->sdist_x - dda->ddist_x);
	else
		dda->perpWallDist = (dda->sdist_y - dda->ddist_y);
}
