/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:24 by erick             #+#    #+#             */
/*   Updated: 2024/01/14 18:02:33 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	create_img(t_cube *cube, t_minimap **mini)
{
	int	i;
	int	j;

	*mini = malloc(sizeof(t_minimap));
	if (mini == NULL)
		exit(ft_exiterror(BRED"Malloc minimap"COLOR_OFF));
	(*mini)->height = SIZE_MINI;
	(*mini)->width = SIZE_MINI;
	(*mini)->img = mlx_new_image(cube->mlx->mlx,
			(*mini)->width, (*mini)->height);
	if ((*mini)->img == NULL)
		exit(ft_exiterror(BRED"Creating minimap image"COLOR_OFF));
	(*mini)->buffer = (int *)mlx_get_data_addr((*mini)->img,
			&(*mini)->bpp, &(*mini)->size_line, &(*mini)->endian);
	if ((*mini)->buffer == NULL)
		exit(ft_exiterror(BRED"Creating minimap buffer"COLOR_OFF));
	i = -1;
	while (++i < (*mini)->height)
	{
		j = -1;
		while (++j < (*mini)->width)
			(*mini)->buffer[i * (*mini)->width + j] = MINI_FLOOR;
	}
}

void	clean_minimap(t_minimap *mini)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mini->height)
	{
		j = -1;
		while (++j < mini->width)
			mini->buffer[i * mini->width + j] = MINI_FLOOR;
	}
}

void	add_mini_walls(t_cube *cube, t_minimap *mini)
{
	t_mini_walls	walls;

	walls.buffer = mini->buffer;
	set_pos(&walls.start, cube->p->pos.x * 24 - 100, cube->p->pos.y * 24 - 100);
	walls.iter.y = -1;
	while (++walls.iter.y < SIZE_MINI)
	{
		walls.iter.x = -1;
		while (++walls.iter.x < SIZE_MINI)
		{
			set_pos_int(&walls.map, (int)((walls.start.x + walls.iter.x) / 24),
				(int)((walls.start.y + walls.iter.y) / 24));
			if (walls.map.x >= 0 && walls.map.x < cube->data_map.w
				&& walls.map.y >= 0 && walls.map.y < cube->data_map.h)
			{
				walls.pos = (int)walls.iter.y * SIZE_MINI + (int)walls.iter.x;
				if (cube->map[walls.map.y][walls.map.x] == '1')
					walls.buffer[walls.pos] = 0x00000000;
				else if (cube->map[walls.map.y][walls.map.x] == 'D')
					walls.buffer[walls.pos] = 0x00FFD700;
				else if (cube->map[walls.map.y][walls.map.x] == 'd')
					walls.buffer[walls.pos] = 0x00FFD790;
			}
		}
	}
}

t_minimap	*ft_init_minimap(t_cube *cube, t_minimap **mini)
{
	create_img(cube, mini);
	return (*mini);
}
