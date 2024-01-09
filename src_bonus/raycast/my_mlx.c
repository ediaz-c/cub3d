/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:26:13 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/09 20:29:45 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = (char *)img->buffer + (y * img->size_line + x * (img->bpp / 8));
	if (color != *(int *)dst)
		*(unsigned int *)dst = color;
}
