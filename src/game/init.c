/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:00:23 by erick             #+#    #+#             */
/*   Updated: 2023/10/23 19:57:01 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

t_mlx	*ft_init_mlx(t_mlx	**mlx, int height, int width)
{
	*mlx = malloc(sizeof(t_mlx));

	if (*mlx == NULL)
		return (NULL);
	(*mlx)->mlx = mlx_init();
	(*mlx)->mlx_win = mlx_new_window((*mlx)->mlx, width, height, "CUB3D");
	return (*mlx);
}

double ft_abs(double nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void paint_line(t_dda *dda, t_cube *cube, t_line *line, int x)
{
    int line_height = (int)(cube->win_height / dda->perpWallDist);
    int draw_start = -line_height / 2 + cube->win_height / 2;
    if (draw_start < 0)
        draw_start = 0;
    int draw_end = line_height / 2 + cube->win_height / 2;
    if (draw_end >= cube->win_height)
        draw_end = cube->win_height - 1;
    int color = 7777; // Elige un color apropiado para pintar la línea

    while (draw_start < draw_end)
    {
        mlx_pixel_put(cube->mlx->mlx, cube->mlx->mlx_win, x, draw_start, color);
        draw_start++;
    }
}


int	prueba(void *ptr)
{
	t_cube		*cube;
	t_dda		dda;
	t_line		line;
	int			i;

	cube = ptr;
	i = -1;
	if (cube->redraw)
	{
		ft_ceiling(cube);
		ft_floor(cube);
		ft_init_dda(&dda, cube);
		while (++i < dda.win_width)
		{
			ft_first_op(&dda, i);
			ft_calculate_side_dist(&dda);
			ft_calculate_dda(&dda, cube->map);
			paint_line(&dda, cube, &line, i);
		}
		printf("a\n");
		cube->redraw = 0;
	}
	return (1);
}

int	key_press(int keycode, t_cube *cube)
{
	t_player	*p;

	p = cube->p;
	if (keycode == 123)
	{
		double	oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(-1) - p->dir_y * sin(-1);
		p->dir_y = oldDirX * sin(-1) + p->dir_y * cos(-1);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(-1) - p->plane_y * sin(-1);
		p->plane_y = oldPlaneX * sin(-1) + p->plane_y * cos(-1);
		cube->redraw = 1;
	}
	printf("%d\n", keycode);
	return (1);
}

void	init_game(t_cube *cube)
{
	if (ft_init_mlx(&cube->mlx, cube->win_height, cube->win_width) == NULL)
		return ;
	if (ft_init_textures(cube) == 0)
		return ;
	cube->redraw = 1;
	mlx_hook(cube->mlx->mlx_win, 2, (1L<<0), key_press, cube);
	mlx_loop_hook(cube->mlx->mlx, prueba, cube);
	mlx_loop(cube->mlx->mlx);
}