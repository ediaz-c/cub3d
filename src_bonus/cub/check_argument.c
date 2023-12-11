/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:04:38 by erick             #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		return (EXIT_FAILURE);
	last = last_index(sp_path);
	ext = ft_strrchr(sp_path[last], '.');
	if (ext == NULL)
		return (free_split(sp_path), EXIT_FAILURE);
	while (ext[i])
	{
		if (ext[i] != format[i])
			return (free_split(sp_path), EXIT_FAILURE);
		i++;
	}
	cube->path = path;
	free_split(sp_path);
	return (EXIT_SUCCESS);
}
