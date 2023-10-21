/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:22:25 by erick             #+#    #+#             */
/*   Updated: 2023/10/21 12:17:54 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int ac, char *av[])
{
	t_cube	*cube;

	atexit(leaks);
	if (ac != 2)
		exit(ft_exiterror(BRED"Invalids arguments"COLOR_OFF));
	if (create_cube(&cube) == NULL)
		exit(1);
	if (ft_check_format(av[1], cube) == 0)
		exit(ft_exiterror(BRED"Invalid extension"COLOR_OFF));
	ft_get_cube(cube);
	// if (ft_check_map(&cube) == 0)
	// 	exit(ft_exiterror(BRED"Invalid map"COLOR_OFF));
	for (int i = 0; cube->file[i]; i++)
		printf("%s\n", cube->file[i]);
	ft_free_cube(cube);
}
