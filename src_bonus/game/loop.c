/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:12:51 by erick             #+#    #+#             */
/*   Updated: 2024/01/31 12:43:34 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_minimap(t_cube *cube)
{
	t_minimap	*mini;
	t_mlx		*mlx;

	mini = cube->mini;
	mlx = cube->mlx;
	clean_minimap(mini);
	add_mini_walls(cube, mini);
	add_mini_player(cube, mini);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mini->img, 10, 10);
}

void	ft_add_extra_info(t_cube *cube)
{
	t_img	*img;
	int		x;
	int		y;
	int		center_h;
	int		center_w;

	img = &cube->img;
	center_h = WIN_H / 2;
	center_w = WIN_W / 2;
	y = center_h - 7;
	while (y <= center_h + 7)
	{
		x = center_w - 1;
		while (x <= center_w + 1)
			my_img_pixel_put(img, x++, y, 0x00FFFFFF);
		y++;
	}
	x = center_w - 7;
	while (x <= center_w + 7)
	{
		y = center_h - 1;
		while (y <= center_h + 1)
			my_img_pixel_put(img, x, y++, 0x00FFFFFF);
		x++;
	}
}

int	render(t_cube *cube)
{
	if (cube->run == REFRESH)
	{
		raycasting(cube);
		ft_add_extra_info(cube);
		mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win,
			cube->img.img, 0, 0);
		ft_put_minimap(cube);
		cube->run = -(cube->run);
	}
	if (cube->mouse_listen == 1)
		mouse_listening(cube);
	return (1);
}
