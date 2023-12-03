/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:16:07 by erick             #+#    #+#             */
/*   Updated: 2023/12/03 16:46:19 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	split_digit(char **color)
{
	int	i;
	int	j;

	i = -1;
	if (color == NULL)
		return (EXIT_FAILURE);
	while (color[++i])
	{
		j = -1;
		while (color[i][++j])
		{
			if (!ft_isdigit(color[i][j]))
				return (EXIT_FAILURE);
		}
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
			return (EXIT_FAILURE);
	}
	if (i != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	get_color(char **color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (0x0 | r << 16 | g << 8 | b);
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
		return (EXIT_FAILURE);
	}
	if (split_digit(ceiling) == 1 || split_digit(floor) == 1)
		return (free_split(ceiling), free_split(floor), EXIT_FAILURE);
	cube->octal_c = get_color(ceiling);
	cube->octal_f = get_color(floor);
	free_split(ceiling);
	free_split(floor);
	if (cube->octal_c == -1 || cube->octal_f == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
