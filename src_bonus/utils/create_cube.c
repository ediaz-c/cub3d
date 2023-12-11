/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:32 by erick             #+#    #+#             */
/*   Updated: 2023/12/07 22:54:45 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*TODO*/
int	ft_count_lines(char *path, int *fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(*fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(*fd);
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
		exit(ft_exiterror(BRED"Path invalid"COLOR_OFF));
	return (i);
}

char	**ft_fd_map(char *path, int fd)
{
	char	*line;
	char	**map;
	int		lines;
	char	*tmp;
	int		i;

	i = -1;
	lines = ft_count_lines(path, &fd);
	map = malloc(sizeof(char *) * (lines + 1));
	if (map == NULL)
		return (NULL);
	while (i++ < lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strtrim(line, "\n");
		free(line);
		map[i] = tmp;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	ft_line_empty(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (EXIT_SUCCESS);
		i++;
	}
	free(line);
	return (EXIT_FAILURE);
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
