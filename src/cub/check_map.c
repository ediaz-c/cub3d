/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:33:17 by erick             #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				return (EXIT_FAILURE);
			if (ft_strchr(CHARS_P, c))
				p++;
		}
	}
	if (p != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
				set_pos(&player->pos, x, y);
				player->pos.x += 0.5;
				player->pos.y += 0.5;
				ft_check_dir(player, map[y][x]);
				break ;
			}
		}
	}
}

int	ft_check_borders(t_player *p, char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	(void)p;
	if (ft_cpy_matrix(map, &map_cpy) == NULL)
		return (EXIT_FAILURE);
	while (map_cpy[i])
	{
		if (i == 0 || map_cpy[i + 1] == NULL)
		{
			if (ft_check_horizontal(map_cpy[i], i, map) == 0)
				return (free_split(map_cpy), EXIT_FAILURE);
		}
		else if (ft_check_rest_rows(map_cpy, i) == 0)
			return (free_split(map_cpy), EXIT_FAILURE);
		i++;
	}
	free_split(map_cpy);
	return (EXIT_SUCCESS);
}

char	*add_spaces(char *str, int max_len)
{
	char	*spaces;
	char	*tmp;

	tmp = str;
	spaces = ft_calloc(max_len - ft_strlen(str) + 1, sizeof(char));
	if (spaces == NULL)
		exit(ft_exiterror("Malloc error"));
	ft_memset(spaces, ' ', max_len - ft_strlen(str));
	str = ft_strjoin(str, spaces);
	if (str == NULL)
		exit(ft_exiterror("Malloc error"));
	free(spaces);
	if (tmp)
		free(tmp);
	return (str);
}

void	ft_fill_map(char **map)
{
	int	i;
	int	max_len;
	char	*spaces;
	
	i = -1;
	max_len = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
	}
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) < max_len)
			map[i] = add_spaces(map[i], max_len);
	}
}
