/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:37 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/14 15:12:20 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotate_left(t_cube *cube, double rot_speed)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = cube->p;
	old_dir_x = p->dir.x;
	p->dir.x = p->dir.x * cos(-rot_speed) - p->dir.y * sin(-rot_speed);
	p->dir.y = old_dir_x * sin(-rot_speed) + p->dir.y * cos(-rot_speed);
	old_plane_x = p->plane.x;
	p->plane.x = p->plane.x * cos(-rot_speed) - p->plane.y * sin(-rot_speed);
	p->plane.y = old_plane_x * sin(-rot_speed) + p->plane.y * cos(-rot_speed);
}

void	ft_rotate_right(t_cube *cube, double rot_speed)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = cube->p;
	old_dir_x = p->dir.x;
	p->dir.x = p->dir.x * cos(rot_speed) - p->dir.y * sin(rot_speed);
	p->dir.y = old_dir_x * sin(rot_speed) + p->dir.y * cos(rot_speed);
	old_plane_x = p->plane.x;
	p->plane.x = p->plane.x * cos(rot_speed) - p->plane.y * sin(rot_speed);
	p->plane.y = old_plane_x * sin(rot_speed) + p->plane.y * cos(rot_speed);
}
