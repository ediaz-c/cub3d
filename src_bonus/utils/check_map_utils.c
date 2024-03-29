/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:47:59 by erick             #+#    #+#             */
/*   Updated: 2024/02/21 10:54:56 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_cpy_matrix(char **matrix, char ***cpy_ptr)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	(*cpy_ptr) = malloc(sizeof(char *) * (i + 1));
	if ((*cpy_ptr) == NULL)
		return (NULL);
	i = -1;
	while (matrix[++i])
	{
		(*cpy_ptr)[i] = ft_strdup(matrix[i]);
		if ((*cpy_ptr)[i] == NULL)
			exit(ft_exiterror(BRED"Malloc"COLOR_OFF));
	}
	(*cpy_ptr)[i] = 0;
	return (*cpy_ptr);
}

int	ft_check_horizontal(char *line, int r, char **map)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(line) - 1;
	while (line[end] == ' ')
		end--;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		while (line[i] == '1')
			i++;
		if (i - 1 == end)
			return (1);
		if (ft_check_spaces(i, r, map) == 0)
			return (0);
	}
	return (1);
}

int	ft_check_rest_rows(char **map, int row)
{
	if (ft_left_up(map, row) == 0)
		return (0);
	if (ft_left_down(map, row) == 0)
		return (0);
	if (ft_right_up(map, row) == 0)
		return (0);
	if (ft_right_down(map, row) == 0)
		return (0);
	return (1);
}

void	ft_check_dir(t_player *player, char dir)
{
	double	fov;

	fov = 0.8;
	set_pos(&player->dir, 0, 0);
	set_pos(&player->plane, 0, 0);
	if (dir == 'N')
	{
		player->dir.y = -0.99;
		player->plane.x = fov;
	}
	else if (dir == 'S')
	{
		player->dir.y = 0.99;
		player->plane.x = -fov;
	}
	else if (dir == 'E')
	{
		player->dir.x = 0.99;
		player->plane.y = fov;
	}
	else if (dir == 'W')
	{
		player->dir.x = -0.99;
		player->plane.y = -fov;
	}
}

void	ft_dimensions_map(char **map, int *height, int *witdh)
{
	int	i;

	i = -1;
	*witdh = 0;
	while (map[++i])
	{
		if (*witdh < (int)ft_strlen(map[i]))
			*witdh = ft_strlen(map[i]);
	}
	*height = i;
}
