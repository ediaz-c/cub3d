/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:22:25 by erick             #+#    #+#             */
/*   Updated: 2024/01/09 16:22:26 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

void	ft_check_args(int ac, char *av[], t_cube **cube)
{
	t_cube	*cube_ptr;

	if (create_cube(&cube_ptr) == NULL)
		exit(ft_exiterror(BRED"Creating cube"COLOR_OFF));
	if (ac != 2)
		exit(ft_exiterror(BRED"Invalids arguments"COLOR_OFF));
	if (ft_check_format(av[1], cube_ptr))
		exit(ft_exiterror(BRED"Invalid extension"COLOR_OFF));
	*cube = cube_ptr;
}

int	main(int ac, char *av[])
{
	t_cube	*cube;

	// atexit(leaks);
	ft_check_args(ac, av, &cube);
	ft_get_cube(cube);
	game(cube);
	ft_free_cube(cube);
	exit (0);
	return (0);
}
