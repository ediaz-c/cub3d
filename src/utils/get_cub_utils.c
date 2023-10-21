/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:16:07 by erick             #+#    #+#             */
/*   Updated: 2023/10/21 23:46:40 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	split_digit(char **color)
{
	int	i;
	int	j;

	i = -1;
	if (color == NULL)
		return (0);
	while (color[++i])
	{
		j = -1;
		while (color[i][++j])
		{
			if (!ft_isdigit(color[i][j]))
				return (0);
		}
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
		{
			return (0);
		}
	}
	if (i != 3)
		return (0);
	return (1);
}

static int	get_color(char **color)
{
	char	*result;
	char	*tmp;
	int		rgb;

	tmp = ft_strjoin(color[0], color[1]);
	result = ft_strjoin(tmp, color[2]);
	if (result == NULL)
		return (-1);
	free(tmp);
	rgb = ft_atoi(result);
	free(result);
	return (rgb);
}

int	ft_get_colors(t_cube *cube)
{
	char	**ceiling;
	char	**floor;

	ceiling = ft_split(cube->c, ',');
	floor = ft_split(cube->f, ',');
	if (ceiling == NULL || floor == NULL)
	{
		if (ceiling)
			free_split(ceiling);
		if (floor)
			free_split(floor);
		return (0);
	}
	if (split_digit(ceiling) == 0 || split_digit(floor) == 0)
		return (free_split(ceiling), free_split(floor), 0);
	cube->crgb = get_color(ceiling);
	cube->frgb = get_color(floor);
	if (cube->crgb == -1 || cube->frgb == -1)
		return (free_split(ceiling), free_split(floor), 0);
	free_split(ceiling);
	free_split(floor);
	return (1);
}
