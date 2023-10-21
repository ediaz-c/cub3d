/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:54 by erick             #+#    #+#             */
/*   Updated: 2023/10/22 01:13:54 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_exiterror(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

int	ft_exiterror_cube(char *str, t_cube *cube)
{
	ft_free_cube(cube);
	ft_putendl_fd(str, 2);
	return (1);
}
