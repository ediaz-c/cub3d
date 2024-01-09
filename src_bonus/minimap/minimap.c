/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:24 by erick             #+#    #+#             */
/*   Updated: 2024/01/09 14:36:55 by ediaz--c         ###   ########.fr       */
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

	walls.start_x = cube->p->pos.x * 24 - 100;
	walls.start_y = cube->p->pos.y * 24 - 100;
	walls.i = 0;
	while (walls.i < SIZE_MINI)
	{
		walls.j = 0;
		while (walls.j < SIZE_MINI)
		{
			walls.map_x = (int)((walls.start_x + walls.j) / 24);
			walls.map_y = (int)((walls.start_y + walls.i) / 24);
			if (walls.map_x >= 0 && walls.map_x < cube->data_map.w
				&& walls.map_y >= 0 && walls.map_y < cube->data_map.h)
			{
				if (cube->map[walls.map_y][walls.map_x] == '1')
					mini->buffer[(int)walls.i
						* SIZE_MINI + (int)walls.j] = 0x00000000;
				else if (cube->map[walls.map_y][walls.map_x] == 'D')
					mini->buffer[(int)walls.i
						* SIZE_MINI + (int)walls.j] = 0x00FFD700;
			}
			walls.j++;
		}
		walls.i++;
	}
}

t_minimap	*ft_init_minimap(t_cube *cube, t_minimap **mini)
{
	create_img(cube, mini);
	return (*mini);
}
