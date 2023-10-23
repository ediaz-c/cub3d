/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:02:25 by erick             #+#    #+#             */
/*   Updated: 2023/10/23 17:06:52 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_floor(t_cube *cube)
{
	int		i;
	int		j;
	t_mlx	*mlx;

	i = cube->win_height / 2;
	mlx = cube->mlx;
	while (i < cube->win_height)
	{
		j = -1;
		while (++j < cube->win_width)
		{
			mlx_pixel_put(mlx->mlx, mlx->mlx_win, j, i, cube->frgb);
		}
		i++;
	}
}

void	ft_ceiling(t_cube *cube)
{
	int		i;
	int		j;
	int		mid_height;
	t_mlx	*mlx;

	i = 0;
	mlx = cube->mlx;
	mid_height = cube->win_height / 2;
	while (i < mid_height)
	{
		j = -1;
		while (++j < cube->win_width)
		{
			mlx_pixel_put(mlx->mlx, mlx->mlx_win, j, i, cube->crgb);
		}
		i++;
	}
}
