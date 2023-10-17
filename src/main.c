/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:22:25 by erick             #+#    #+#             */
/*   Updated: 2023/10/17 15:30:03 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int ac, char *av[])
{
	t_cube	cube;
	// atexit(leaks);
	if (ac != 2)
		exit(ft_exiterror(BRed"Invalids arguments"Color_off));
	if (ft_check_format(av[1], &cube) == 0)
		exit(ft_exiterror(BRed"Invalid extension"Color_off));
	if (ft_get_map(&cube) == 0)
		exit(ft_exiterror(BRed"Invalid map"Color_off));
	printf("BIEN");
}