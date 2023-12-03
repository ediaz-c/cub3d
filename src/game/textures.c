/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:09 by erick             #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
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
		return (free(img), NULL);
	img->buffer = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	if (img->buffer == NULL)
		return (free(img), NULL);
	return (img);
}

t_img	*ft_create_env(t_img *env, int color, t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	env->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H / 2);
	if (env->img == NULL)
		return (NULL);
	env->buffer =(int *) mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	if (env->buffer == NULL)
	{
		mlx_destroy_image(mlx->mlx, env->img);
		return (NULL);
	}
	env->size_line /= 4;
	color = mlx_get_color_value(mlx->mlx, color);
	while (++y < WIN_H / 2)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (y * env->size_line + x < WIN_W * (WIN_H / 2))
				env->buffer[(y * env->size_line) + x] = color;
		}
	}
	return (env);
}

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
	if (ft_create_env(&cube->txt->flo, cube->octal_f, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_create_env(&cube->txt->cei, cube->octal_c, cube->mlx) == NULL)
		return (EXIT_FAILURE);
	if (ft_get_img_cube(cube) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
