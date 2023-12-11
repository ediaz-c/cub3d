/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:12:51 by erick             #+#    #+#             */
/*   Updated: 2023/12/09 02:28:25 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render(t_cube *cube)
{
	if (cube->run == 1)
	{
		raycasting(cube);
		mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win, cube->img.img,
			0, 0);
		cube->run = -(cube->run);
	}
	return (1);
}
