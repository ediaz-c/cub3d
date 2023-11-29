/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:25:34 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/11/29 20:26:48 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_xcamera(t_cube *cube)
{
	int		x;

	x = -1;
	while (++x < WIN_W)
		cube->camera_x[x] = 2 * x / (double)WIN_W - 1;
}
