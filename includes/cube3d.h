/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:22:41 by erick             #+#    #+#             */
/*   Updated: 2023/10/21 23:24:16 by erick            ###   ########.fr       */
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

typedef struct s_cube
{
	char			*path;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*f;
	char			*c;
	char			**file;
	char			**map;
	int				crgb;
	int				frgb;
	int				first_line;
	struct s_player	*p;
}	t_cube;

typedef struct s_player
{
	float	x;
	float	y;
	char	dir;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
}	t_mlx;

/***** FREE *****/
/* free_str.c */
void	free_split(char **split);
/* free_cube.c */
void	ft_free_cube(t_cube *cube);

/***** MAP *****/
// Argument
int		ft_check_format(char *path, t_cube *cube);
/* check_map.c */
int	ft_check_chars(char **map);
void	ft_find_player(t_player *player, char **map);
int	ft_check_borders(t_player *p, char **map);
/* get_cub.c */
void	ft_get_cube(t_cube *cube);
int		ft_check_map(t_cube *cube);

/***** ERROR *****/
int		ft_exiterror(char *str);
int		ft_exiterror_cube(char *str, t_cube *cube);

/***** UTILS *****/
/* create_cube.c */
t_cube	*create_cube(t_cube **cube);
int		ft_search_elements(t_cube *cube, char *id, char *path);
int		ft_line_empty(char	*line);
char	**ft_fd_map(int fd);
/* check_map_utils.c */
char	**ft_cpy_matrix(char **matrix, char ***cpy_ptr);
int	ft_check_horizontal(char *line, int r, char **map);
int	ft_check_rest_rows(char **map, int row);
/* check_row.c */
int	ft_left_up(char **map, int r);
int	ft_left_down(char **map, int r);
int	ft_right_up(char **map, int r);
int	ft_right_down(char **map, int r);
int	ft_check_spaces(int x, int y, char **map);
/* get_cub_utils.c */
int	ft_get_colors(t_cube *cube);
#endif