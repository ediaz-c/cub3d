/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:54 by erick             #+#    #+#             */
/*   Updated: 2023/12/07 22:45:12 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exiterror(char *str)
{
	ft_putendl_fd(BRED"Error"COLOR_OFF, 2);
	ft_putendl_fd(str, 2);
	return (1);
}

int	ft_exiterror_cube(char *str, t_cube *cube)
{
	ft_free_cube(cube);
	ft_putendl_fd(BRED"Error"COLOR_OFF, 2);
	ft_putendl_fd(str, 2);
	return (1);
}
