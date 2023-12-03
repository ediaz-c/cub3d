/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:23:42 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/03 16:44:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// typedef struct s_player
// {
// // 	t_pos	pos; 
// // 	t_pos	dir;
// 	t_pos	x_dir;
// 	t_pos	plane;
// 	t_img	img;
// }	t_player;

void	ft_init_player(t_cube *cube)
{
	t_player	*p;

	p = cube->p;
	p->move_speed = 0.5;
	p->rot_speed = 0.3;
}