/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:47:59 by erick             #+#    #+#             */
/*   Updated: 2023/10/21 22:35:39 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	**ft_cpy_matrix(char **matrix, char ***cpy_ptr)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	(*cpy_ptr) = malloc(sizeof(char *) * (i + 1));
	if ((*cpy_ptr) == NULL)
		return (NULL);
	i = -1;
	while (matrix[++i])
		(*cpy_ptr)[i] = ft_strdup(matrix[i]);
	(*cpy_ptr)[i] = 0;
	return (*cpy_ptr);
}

int	ft_check_horizontal(char *line, int r, char **map)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(line) - 1;
	while (line[end] == ' ')
		end--;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		while (line[i] == '1')
			i++;
		if (i - 1 == end)
			return (1);
		if (ft_check_spaces(i, r, map) == 0)
			return (0);
	}
	return (1);
}

int	ft_check_rest_rows(char **map, int row)
{
	if (ft_left_up(map, row) == 0)
		return (0);
	if (ft_left_down(map, row) == 0)
		return (0);
	if (ft_right_up(map, row) == 0)
		return (0);
	if (ft_right_down(map, row) == 0)
		return (0);
	return (1);
}