/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:33:17 by erick             #+#    #+#             */
/*   Updated: 2023/10/21 22:50:51 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

/*
*	0 Espacio vacío
*	1 Muro
*	Jugador
*	N Norte
*	S SUR
*	E Este
*	W oeste
*/
int	ft_check_chars(char **map)
{
	int		i;
	int		j;
	int		p;
	char	c;

	i = -1;
	p = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			c = map[i][j];
			if (ft_strchr(CHARS_MAP, c) == 0)
				return (0);
			if (ft_strchr(CHARS_P, c))
				p++;
		}
	}
	if (p != 1)
		return (0);
	return (1);
}

void	ft_find_player(t_player *player, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr(CHARS_P, map[y][x]))
			{
				player->y = y;
				player->x = x;
				player->dir = map[y][x];
				break ;
			}
		}
	}
}

// int	ft_all_close(int p_x, int p_y, char **map)
// {
// 	map[p_y][p_x] = ' ';
// 	if (ft_check_around(p_y, p_x, map) == 0)
// 		return (0);
// 	if (p_y - 1 >= 0 && map[p_y - 1][p_x] == '0')
// 		if (ft_all_close(p_x, p_y - 1, map) == 0)
// 			return (0);
// 	if (map[p_y + 1] && map[p_y + 1][p_x] == '0')
// 		if (ft_all_close(p_x, p_y + 1, map) == 0)
// 			return (0);
// 	if (p_x - 1 >= 0 && map[p_y][p_x - 1] == '0')
// 		if (ft_all_close(p_x - 1, p_y, map) == 0)
// 			return (0);
// 	if (map[p_y][p_x + 1] && map[p_y][p_x + 1] == '0')
// 		if (ft_all_close(p_x + 1, p_y, map) == 0)
// 			return (0);
// 	return (1);
// }

int	ft_check_borders(t_player *p, char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	(void)p;
	if (ft_cpy_matrix(map, &map_cpy) == NULL)
		return (0);
	// if (ft_all_close((int)p->x, (int)p->y, map_cpy) == 0)
	// 	return (0);
	while (map_cpy[i])
	{
		if (i == 0 || map_cpy[i + 1] == NULL)
		{
			if (ft_check_horizontal(map_cpy[i], i, map) == 0)
				return (free_split(map_cpy), 0);
		}
		else if (ft_check_rest_rows(map_cpy, i) == 0)
			return (free_split(map_cpy), 0);
		i++;
	}
	
	free_split(map_cpy);
	return (1);
}