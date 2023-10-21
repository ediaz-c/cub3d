/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:32 by erick             #+#    #+#             */
/*   Updated: 2023/10/22 01:13:54 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**ft_fd_map(int fd)
{
	char	*line;
	char	*tmp;
	char	*map_str;
	char	**map;

	tmp = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_line_empty(line))
			continue ;
		map_str = ft_strjoin(tmp, line);
		free(tmp);
		tmp = map_str;
		if (tmp == NULL)
			return (close(fd), free(line), NULL);
		free(line);
	}
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

int	ft_line_empty(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	free(line);
	return (1);
}

int	ft_search_elements(t_cube *cube, char *id, char *path)
{
	if (ft_strncmp(id, "NO", 2) == 0 && ft_strlen(id) == 2)
		cube->no = ft_strdup(path);
	else if (ft_strncmp(id, "SO", 2) == 0 && ft_strlen(id) == 2)
		cube->so = ft_strdup(path);
	else if (ft_strncmp(id, "EA", 2) == 0 && ft_strlen(id) == 2)
		cube->ea = ft_strdup(path);
	else if (ft_strncmp(id, "WE", 2) == 0 && ft_strlen(id) == 2)
		cube->we = ft_strdup(path);
	else if (ft_strncmp(id, "F", 1) == 0 && ft_strlen(id) == 1)
		cube->f = ft_strdup(path);
	else if (ft_strncmp(id, "C", 1) == 0 && ft_strlen(id) == 1)
		cube->c = ft_strdup(path);
	else
		return (0);
	return (1);
}

t_cube	*create_cube(t_cube **cube)
{
	(*cube) = malloc(sizeof(t_cube));
	if ((*cube) == NULL)
		return (NULL);
	(*cube)->p = malloc(sizeof(t_player));
	if ((*cube)->p == NULL)
		return (free(cube), NULL);
	(*cube)->path = NULL;
	(*cube)->file = NULL;
	(*cube)->map = NULL;
	(*cube)->no = NULL;
	(*cube)->so = NULL;
	(*cube)->ea = NULL;
	(*cube)->we = NULL;
	(*cube)->f = NULL;
	(*cube)->c = NULL;
	(*cube)->first_line = 0;
	return (*cube);
}
