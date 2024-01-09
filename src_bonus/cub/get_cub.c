/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:30 by erick             #+#    #+#             */
/*   Updated: 2024/01/09 14:40:41 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_get_file(t_cube *cube)
{
	int		fd;

	fd = open(cube->path, O_RDONLY);
	if (fd < 0)
		exit(ft_exiterror(BRED"Path invalid"COLOR_OFF));
	
	cube->file = ft_fd_map(cube->path, fd);
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
		if (info[0] == NULL)
		{
			free_split(info);
			continue ;
		}
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
	ft_fill_map(cube->map);
	if (ft_check_chars(cube->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_find_player(cube->p, cube->map);
	if (ft_check_borders(cube->p, cube->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_get_cube(t_cube *cube)
{
	if (ft_get_file(cube) == 0)
		exit(ft_exiterror_cube(BRED"Getting the file"COLOR_OFF, cube));
	if (ft_get_elements(cube) == 0)
		exit(ft_exiterror_cube(BRED"Getting elements"COLOR_OFF, cube));
	if (ft_get_colors(cube))
		exit(ft_exiterror_cube(BRED"Checking colors"COLOR_OFF, cube));
	if (ft_get_map(cube) == 0)
		exit(ft_exiterror_cube(BRED"Getting map"COLOR_OFF, cube));
	if (ft_check_map(cube))
		exit(ft_exiterror_cube(BRED"Map invalid"COLOR_OFF, cube));
	ft_change_chars(cube->map, cube->p);
	ft_size_map(cube);
	ft_init_player(cube);
	cube->run = 1;
	set_pos(&cube->door_handler, 0, 0);
}
