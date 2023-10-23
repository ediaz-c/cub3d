/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:30 by erick             #+#    #+#             */
/*   Updated: 2023/10/23 16:13:42 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_file(t_cube *cube)
{
	int		fd;

	fd = open(cube->path, O_RDONLY);
	if (fd < 0)
		exit(ft_exiterror(BRED"Path error"COLOR_OFF));
	
	cube->file = ft_fd_map(fd);
	if (cube->file == NULL)
		return (close(fd), 0);
	return (close(fd), 1);
}

int	ft_get_elements(t_cube *cube)
{
	int		i;
	char	**info;

	i = -1;
	while (cube->file[++i])
	{
		info = ft_split(cube->file[i], ' ');
		if (info == NULL)
			return (free_split(info), 0);
		if (ft_search_elements(cube, info[0], info[1]) == 0)
			break ;
		free_split(info);
	}
	free_split(info);
	if (!cube->no || !cube->so || !cube->ea
		|| !cube->we || !cube->f || !cube->c)
		return (0);
	cube->first_line = i;
	return (1);
}

int	ft_get_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = cube->first_line;
	while (cube->file[i])
		++i;
	cube->map = malloc(sizeof(char *) * (i - j + 1));
	if (cube->map == NULL)
		return (0);
	i = 0;
	while (cube->file[j])
	{
		cube->map[i++] = ft_strdup(cube->file[j++]);
		if (cube->map[i - 1] == NULL)
			return (0);
	}
	cube->map[i] = 0;
	return (1);
}

int	ft_check_map(t_cube *cube)
{
	if (ft_check_chars(cube->map) == 0)
		return (0);
	ft_find_player(cube->p, cube->map);
	if (ft_check_borders(cube->p, cube->map) == 0)
		return (0);
	return (1);
}

void	ft_get_cube(t_cube *cube)
{
	if (ft_get_file(cube) == 0)
		exit(ft_exiterror_cube(BRED"Error getting the file"COLOR_OFF, cube));
	if (ft_get_elements(cube) == 0)
		exit(ft_exiterror_cube(BRED"Error getting elements"COLOR_OFF, cube));
	if (ft_get_colors(cube) == 0)
		exit(ft_exiterror_cube(BRED"Error checking colors"COLOR_OFF, cube));
	if (ft_get_map(cube) == 0)
		exit(ft_exiterror_cube(BRED"Error getting map"COLOR_OFF, cube));
	if (ft_check_map(cube) == 0)
		exit(ft_exiterror_cube(BRED"Map invalid"COLOR_OFF, cube));
	cube->win_height = 780;
	cube->win_width = 1220;
}
