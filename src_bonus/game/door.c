/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:46:38 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/14 17:54:59 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_state_door(t_cube *cube)
{
	t_pos	door;
	char	player_pos;

	player_pos = cube->map[(int)cube->p->pos.y][(int)cube->p->pos.x];
	if (player_pos != 'd')
	{
		set_pos(&door, cube->door_handler.x, cube->door_handler.y);
		if (door.x != -1 && door.y != -1)
		{
			if (cube->map[(int)door.y][(int)door.x] == 'D')
				cube->map[(int)door.y][(int)door.x] = 'd';
			else if (cube->map[(int)door.y][(int)door.x] == 'd')
				cube->map[(int)door.y][(int)door.x] = 'D';
			cube->run = REFRESH;
		}
	}
}
