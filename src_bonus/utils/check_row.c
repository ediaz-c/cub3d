/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:35:25 by erick             #+#    #+#             */
/*   Updated: 2024/01/14 15:12:14 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_left_up(char **map, int r)
{
	int	i;

	i = 0;
	while (map[r][i] == ' ')
		i++;
	while (map[r][i] == '1')
	{
		if (map[r - 1][i] == '1')
			return (1);
		else if (i != 0 && map[r - 1][i - 1] == '1')
			return (1);
		else if (map[r - 1][i + 1] && map[r - 1][i + 1] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_left_down(char **map, int r)
{
	int	i;

	i = 0;
	while (map[r][i] == ' ')
		i++;
	while (map[r][i] == '1')
	{
		if (map[r + 1][i] == '1')
			return (1);
		else if (i > 0 && map[r + 1][i - 1] == '1')
			return (1);
		else if (map[r + 1][i + 1] && map[r + 1][i + 1] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_right_up(char **map, int r)
{
	int	ri;

	ri = ft_strlen(map[r]) - 1;
	while (r >= 0 && map[r][ri] == ' ')
		ri--;
	while (r >= 0 && map[r][ri] == '1')
	{
		if (map[r - 1][ri] == '1')
			return (1);
		else if (ri >= 0 && map[r - 1][ri - 1] == '1')
			return (1);
		else if (map[r - 1][ri + 1] && map[r - 1][ri + 1] == '1')
			return (1);
		ri--;
	}
	return (0);
}

int	ft_right_down(char **map, int r)
{
	int	ri;

	ri = ft_strlen(map[r]) - 1;
	while (r >= 0 && map[r][ri] == ' ')
		ri--;
	while (r >= 0 && map[r][ri] == '1')
	{
		if (map[r + 1][ri] == '1')
			return (1);
		else if (ri >= 0 && map[r + 1][ri - 1] == '1')
			return (1);
		else if (map[r + 1][ri + 1] && map[r + 1][ri + 1] == '1')
			return (1);
		ri--;
	}
	return (0);
}

int	ft_check_spaces(int x, int y, char **map)
{
	map[y][x] = '.';
	if ((y - 1 >= 0 && map[y - 1][x] == '0')
		|| (map[y + 1] && map[y + 1][x] == '0'))
		return (0);
	if ((x - 1 >= 0 && map[y][x - 1] == '0')
		|| (map[y][x + 1] && map[y][x + 1] == '0'))
		return (0);
	if (y - 1 >= 0 && map[y - 1][x] == ' ')
		if (ft_check_spaces(x, y - 1, map) == 0)
			return (0);
	if (map[y + 1] && map[y + 1][x] == ' ')
		if (ft_check_spaces(x, y + 1, map) == 0)
			return (0);
	if (x - 1 >= 0 && map[y][x - 1] == ' ')
		if (ft_check_spaces(x - 1, y, map) == 0)
			return (0);
	if (map[y][x + 1] && map[y][x + 1] == ' ')
		if (ft_check_spaces(x + 1, y, map) == 0)
			return (0);
	return (1);
}
