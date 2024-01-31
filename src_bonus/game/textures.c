/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:09 by erick             #+#    #+#             */
/*   Updated: 2024/01/31 12:37:33 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*ft_get_img_cube(t_cube *cube)
{
	cube->img.img = (int *)mlx_new_image(cube->mlx->mlx, WIN_W, WIN_H);
	if (cube->img.img == NULL)
		return (NULL);
	cube->img.buffer = (int *)mlx_get_data_addr(cube->img.img,
			&cube->img.bpp, &cube->img.size_line, &cube->img.endian);
	if (cube->img.buffer == NULL)
		return (NULL);
	return (&cube->img);
}

t_img	*ft_create_img(t_img *img, char *path, t_mlx *mlx)
{
	img->img = mlx_xpm_file_to_image(mlx->mlx, path, &img->width, &img->height);
	if (img->img == NULL)
		return (NULL);
	img->buffer = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	if (img->buffer == NULL)
		return (NULL);
	return (img);
}

t_img	*ft_create_img_color(t_img *img, t_mlx *mlx, int color)
{
	int	x;
	int	y;

	img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_W);
	if (img->img == NULL)
		return (NULL);
	img->buffer = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	if (img->buffer == NULL)
		return (NULL);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			img->buffer[y * WIN_W + x] = color;
	}
	return (img);
}

char	*asset(int asset)
{
	if (asset == CEILING)
		return ("./textures/extra/ceiling_wood.xpm");
	else if (asset == FLOOR)
		return ("./textures/extra/floor.xpm");
	else if (asset == DOOR)
		return ("./textures/extra/door_lab.xpm");
	else if (asset == DOOR_WALL)
		return ("./textures/extra/door_wall_lab.xpm");
	return (NULL);
}

/* TODO  TOO LONG*/
int	ft_init_textures(t_cube *cube)
{
	cube->txt = malloc(sizeof(t_texture));
	if (cube->txt == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->no, cube->no, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->so, cube->so, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->ea, cube->we, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->we, cube->ea, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->door, asset(DOOR), cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->door_wall,
			asset(DOOR_WALL), cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->ceiling, asset(CEILING), cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img(&cube->txt->floor, asset(FLOOR), cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_img_color(&cube->img, cube->mlx, BG_COLOR) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
