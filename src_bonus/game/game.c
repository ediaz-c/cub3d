/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:00:23 by erick             #+#    #+#             */
/*   Updated: 2024/01/12 13:04:06 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

t_mlx	*ft_init_mlx(t_mlx	**mlx)
{
	*mlx = malloc(sizeof(t_mlx));
	if (*mlx == NULL)
		return (NULL);
	(*mlx)->mlx = mlx_init();
	if ((*mlx)->mlx == NULL)
		return (NULL);
	(*mlx)->win = mlx_new_window((*mlx)->mlx, WIN_W, WIN_H, "CUB3D");
	if ((*mlx)->win == NULL)
		return (NULL);
	return (*mlx);
}

void	init_game(t_cube *cube)
{
	if (ft_init_mlx(&cube->mlx) == NULL)
		exit(ft_exiterror(BRED"Initializing mlx"COLOR_OFF));
	if (ft_init_textures(cube) == EXIT_FAILURE)
		exit(ft_exiterror(BRED"Initializing textures"COLOR_OFF));
	if (ft_init_minimap(cube, &cube->mini) == 0)
		exit(ft_exiterror(BRED"Initializing minimap"COLOR_OFF));
}

void	game(t_cube *cube)
{
	t_mlx	*mlx;

	init_game(cube);
	mlx = cube->mlx;
	mlx_loop_hook(mlx->mlx, render, cube);
	mlx_hook(mlx->win, 2, (1L << 0), ft_keypress, cube);
	mlx_hook(mlx->win, 3, (1L << 1), ft_keyrelease, cube);
	mlx_mouse_hook(mlx->win, ft_mouse, cube);
	mlx_hook(mlx->win, 17, (1L << 17), ft_close, mlx);
	mlx_loop(mlx->mlx);
}
