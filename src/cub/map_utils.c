/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:49:25 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_size_map(t_cube *cube)
{
	int height;
	int width;

	height = -1;
	width = ft_strlen(cube->map[0]);
	while (cube->map[++height])
		continue ;
	cube->data_map.h = height;
	cube->data_map.w = width;
}

void	ft_change_chars(char **map, t_player *p)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '.')
				map[y][x] = ' ';
		}
	}
	map[(int)p->pos.y][(int)p->pos.x] = '0';
}