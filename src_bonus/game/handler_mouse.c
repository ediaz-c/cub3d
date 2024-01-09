/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:32:48 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/09 20:13:07 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_mouse(int button, int x, int y, t_cube *cube)
{
	mlx_mouse_hide();
	cube->mouse_listen = 1;
	mlx_mouse_move(cube->mlx->win, WIN_W / 2, WIN_H / 2);
	(void)x;
	(void)y;
	if (button == 2 && cube->map[(int)cube->p->pos.y][(int)cube->p->pos.x] != 'd')
	{
		if (cube->door_handler.x != -1 && cube->door_handler.y != -1 && cube->map[(int)cube->door_handler.y][(int)cube->door_handler.x] == 'D')
		{
			cube->map[(int)cube->door_handler.y][(int)cube->door_handler.x] = 'd';
			cube->run = 1;
		}
		else if (cube->door_handler.x != -1 && cube->door_handler.y != -1 && cube->map[(int)cube->door_handler.y][(int)cube->door_handler.x] == 'd')
		{
			cube->map[(int)cube->door_handler.y][(int)cube->door_handler.x] = 'D';
			cube->run = 1;
		}
	}
	return (1);
}

void	mouse_listening(t_cube *cube)
{
	int		x;
	int		y;
	double	distance;
	double	rot_speed;
	t_mlx	*mlx;

	rot_speed = 0.05;
	mlx = cube->mlx;
	mlx_mouse_get_pos(mlx->win, &x, &y);
	if (x == WIN_W / 2 && y == WIN_H / 2)
		return ;
	distance = WIN_W / 2 - x;
	if (distance < 0)
		distance = -distance;
	distance /= 10;
	if (x > WIN_W / 2)
		ft_rotate_right(cube, rot_speed * distance);
	else if (x < WIN_W / 2)
		ft_rotate_left(cube, rot_speed * distance);
	mlx_mouse_move(mlx->win, WIN_W / 2, WIN_H / 2);
	cube->run = 1;
}
