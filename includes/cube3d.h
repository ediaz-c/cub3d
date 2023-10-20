/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:22:41 by erick             #+#    #+#             */
/*   Updated: 2023/10/19 23:10:12 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libs/libft/includes/libft.h"
# include "color.h"
# include <stdio.h>
# include <fcntl.h>

# define CHARS_MAP	" 01NSEW"
# define CHARS_P	"NSEW"

typedef struct	s_cube
{
	char	*path;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	char	**map;
	int		first_line;
} t_cube;

/***** FREE *****/
/* free_str.c */
void	free_split(char **split);
/* free_cube.c */
void	ft_free_cube(t_cube *cube);

/***** MAP *****/
// Argument
int	ft_check_format(char *path, t_cube *cube);
/* get_cub.c */
void	ft_get_cube(t_cube *cube);
int	ft_check_map(t_cube *cube);

/***** ERROR *****/
int	ft_exiterror(char *str);

/***** UTILS *****/
/* create_cube.c */
t_cube	*create_cube(t_cube **cube);
int	ft_search_elements(t_cube *cube, char *id, char *path);
int	ft_line_empty(char	*line);
char	**ft_fd_map(int fd);
#endif