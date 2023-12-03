/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:19:35 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_keypress(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
		ft_close(keycode, cube->mlx);
	else if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_D)
		ft_handler_move(keycode, cube);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_handler_rotate(keycode, cube);
	else if (keycode == KEY_Q)
	{
		mlx_mouse_show();
		cube->mouse_listen = 0;
	}
	return (1);
}

void	ft_handler_move(int keycode, t_cube *cube)
{
	if (keycode == KEY_W)
		ft_move_up(cube, cube->p, cube->map);
	else if (keycode == KEY_S)
		ft_move_down(cube, cube->p, cube->map);
	else if (keycode == KEY_A)
		ft_move_right(cube, cube->p, cube->map);
	else if (keycode == KEY_D)
		ft_move_left(cube, cube->p, cube->map);
	cube->run = 1;
}

void	ft_handler_rotate(int keycode, t_cube *cube)
{
	if (keycode == KEY_LEFT)
		ft_rotate_left(cube, cube->p->rot_speed);
	else if (keycode == KEY_RIGHT)
		ft_rotate_right(cube, cube->p->rot_speed);
	cube->run = 1;
}
