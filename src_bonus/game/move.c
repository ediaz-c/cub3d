/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:56:25 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/08 16:41:55 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_up(t_cube *cube, t_player *p, char **map)
{
	double		step_size = 0.1;
	double		step;

	step = 0;
	while(step < p->move_speed)
	{
		if ((int)(p->pos.y + p->dir.y * step_size) < cube->data_map.h && 
			map[(int)(p->pos.y + p->dir.y * step_size)][(int)p->pos.x] != '1')
			p->pos.y += p->dir.y * step_size;
		if ((int)(p->pos.x + p->dir.x * step_size) < cube->data_map.w && 
			map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * step_size)] != '1')
			p->pos.x += p->dir.x * step_size;
		step += step_size;
	}
}

void	ft_move_down(t_cube *cube, t_player *p, char **map)
{
	double		step_size = 0.1;
	double		step;

	step = 0;
	(void)cube;
	while(step < p->move_speed)
	{
		if ((int)(p->pos.y - p->dir.y * step_size) >= 0 && 
			map[(int)(p->pos.y - p->dir.y * step_size)][(int)p->pos.x] != '1')
			p->pos.y -= p->dir.y * step_size;
		if ((int)(p->pos.x - p->dir.x * step_size) >= 0 && 
			map[(int)p->pos.y][(int)(p->pos.x - p->dir.x * step_size)] != '1')
			p->pos.x -= p->dir.x * step_size;
		step += step_size;
	}
}

void	ft_move_left(t_cube *cube, t_player *p, char **map)
{
	double		step_size = 0.1;
	double		step;

	step = 0;
	while(step < p->move_speed)
	{
    	if ((int)(p->pos.x - p->dir.y * step_size) >= 0 && 
        	map[(int)p->pos.y][(int)(p->pos.x - p->dir.y * step_size)] != '1')
        	p->pos.x -= p->dir.y * step_size;
		if ((int)(p->pos.y + p->dir.x * step_size) < cube->data_map.h && 
			map[(int)(p->pos.y + p->dir.x * step_size)][(int)p->pos.x] != '1')
			p->pos.y += p->dir.x * step_size;
		step += step_size;
	}
}

void	ft_move_right(t_cube *cube, t_player *p, char **map)
{
	double		step_size = 0.1;
	double		step;

	step = 0;
	while(step < p->move_speed)
	{
    	if ((int)(p->pos.x + p->dir.y * step_size) < cube->data_map.w && 
        	map[(int)p->pos.y][(int)(p->pos.x + p->dir.y * step_size)] != '1')
        	p->pos.x += p->dir.y * step_size;
		if ((int)(p->pos.y - p->dir.x * step_size) >= 0 && 
       		map[(int)(p->pos.y - p->dir.x * step_size)][(int)p->pos.x] != '1')
        	p->pos.y -= p->dir.x * step_size;
		step += step_size;
	}
}
