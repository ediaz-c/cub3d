/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:54 by erick             #+#    #+#             */
/*   Updated: 2023/10/20 10:34:08 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_exiterror(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

int	ft_returnerror(t_cube *cube, char *str)
{
	
}