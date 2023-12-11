/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:54:05 by erick             #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_cube(t_cube *cube)
{
	if (cube->no)
		free(cube->no);
	if (cube->so)
		free(cube->so);
	if (cube->ea)
		free(cube->ea);
	if (cube->we)
		free(cube->we);
	if (cube->f)
		free(cube->f);
	if (cube->c)
		free(cube->c);
	free_split(cube->file);
	if (cube->map)
		free_split(cube->map);
	free(cube->p);
	free(cube);
}
