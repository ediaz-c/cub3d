/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:22:41 by erick             #+#    #+#             */
/*   Updated: 2023/10/17 15:31:15 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libs/libft/includes/libft.h"
# include "color.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_cube
{
	char	*path;
	char	**map;
} t_cube;

/*FREE*/
void	free_split(char **split);
/*MAP*/
// Argument
int	ft_check_format(char *path, t_cube *cube);
// Map
int	ft_get_map(t_cube *cube);
/*ERROR*/
int	ft_exiterror(char *str);
#endif