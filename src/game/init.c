/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:00:23 by erick             #+#    #+#             */
/*   Updated: 2023/10/22 21:44:46 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx	*ft_init_mlx(t_mlx	**mlx, int height, int width)
{
	*mlx = malloc(sizeof(t_mlx));

	if (*mlx == NULL)
		return (NULL);
	(*mlx)->mlx = mlx_init();
	(*mlx)->mlx_win = mlx_new_window((*mlx)->mlx, height, width, "CUB3D");
	return (*mlx);
}

double ft_abs(double nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	prueba(void *ptr)
{
	t_cube		*cube;
	t_player	*p;
	int	i;

	i = -1;
	cube = ptr;
	p = cube->p;
	while (++i < cube->win_width)
	{
		p->camerax = 2 * i / (double)cube->win_width - 1;
		p->raydir_x = p->dir_x + p->plane_x * p->camerax;
		p->raydir_y = p->dir_y + p->plane_y * p->camerax;
	}
	return (1);
}

void	init_game(t_cube *cube)
{
	if (ft_init_mlx(&cube->mlx, cube->win_height, cube->win_width) == NULL)
		return ;
	mlx_loop_hook(cube->mlx->mlx, prueba, cube);
	mlx_loop(cube->mlx->mlx);
}