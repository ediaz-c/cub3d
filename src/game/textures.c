/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:09 by erick             #+#    #+#             */
/*   Updated: 2023/10/23 15:40:44 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*ft_create_img(t_img **img, char	*path, t_mlx *mlx)
{
	*img = malloc(sizeof(t_img));
	if ((*img) == NULL)
		return (NULL);
	(*img)->img = mlx_xpm_file_to_image(mlx->mlx, path, &(*img)->width, &(*img)->height);
	if ((*img)->img == NULL)
		return (free(*img), NULL);
	return (*img);
}

int	ft_init_textures(t_cube *cube)
{
	cube->txt = malloc(sizeof(t_texture));
	if (cube->txt == NULL)
		return (0);
	if (ft_create_img(&cube->txt->no, cube->no, cube->mlx) == NULL)
		return (0);
	if (ft_create_img(&cube->txt->so, cube->so, cube->mlx) == NULL)
		return (0);
	if (ft_create_img(&cube->txt->ea, cube->we, cube->mlx) == NULL)
		return (0);
	if (ft_create_img(&cube->txt->we, cube->ea, cube->mlx) == NULL)
		return (0);
	return (1);
}
