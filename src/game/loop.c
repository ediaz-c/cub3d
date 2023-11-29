/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:12:51 by erick             #+#    #+#             */
/*   Updated: 2023/11/29 20:31:03 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_floor_ceiling(t_cube *cube)
{
	t_mlx		*mlx;
	t_texture	*text;

	mlx = cube->mlx;
	text = cube->txt;
	mlx_put_image_to_window(mlx->mlx, mlx->win, text->flo.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, text->cei.img, 0, WIN_H / 2);
}

void	ft_put_minimap(t_cube *cube)
{
	t_minimap	*mini;
	t_mlx		*mlx;

	mini = cube->mini;
	mlx = cube->mlx;
	clean_minimap(cube, mini);
	add_mini_walls(cube, mini);
	add_mini_player(cube, mini);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mini->img, 10, 10);
}

int	loop(t_cube *cube)
{
	if (cube->run == 1)
	{
		// raycasting(cube);
		ft_put_floor_ceiling(cube);
		ft_put_minimap(cube);
		cube->run = -(cube->run);
	}
	if (cube->mouse_listen == 1)
		mouse_listening(cube);
	return (1);
}