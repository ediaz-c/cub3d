/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:04:38 by erick             #+#    #+#             */
/*   Updated: 2023/10/17 15:19:20 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	last_index(char	**path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (i - 1);
}

int	ft_check_format(char *path, t_cube *cube)
{
	char	**sp_path;
	char	*format;
	char	*ext;
	int		last;
	int		i;

	i = 0;
	format = ".cub";
	sp_path = ft_split(path, '/');
	if (sp_path == NULL)
		return (0);
	last = last_index(sp_path);
	ext = ft_strrchr(sp_path[last], '.');
	if (ext == NULL)
		return(free_split(sp_path), 0);
	while (ext[i])
	{
		if (ext[i] != format[i])
			return(free_split(sp_path), 0);
		i++;
	}
	cube->path = path;
	free_split(sp_path);
	return (1);
}
