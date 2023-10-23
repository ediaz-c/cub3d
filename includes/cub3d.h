/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
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
# include "../libs/mlx/mlx.h"
# include "color.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define CHARS_MAP	" 01NSEW"
# define CHARS_P	"NSEW"

typedef struct s_cube
{
	char				*path;
	char				*no;
	char				*so;
	char				*ea;
	char				*we;
	char				*f;
	char				*c;
	char				**file;
	char				**map;
	int					crgb;
	int					frgb;
	int					first_line;
	int					win_height;
	int					win_width;
	int					redraw;
	struct s_player		*p;
	struct s_mlx		*mlx;
	struct s_texture	*txt;
}	t_cube;


typedef struct	s_img
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct	s_texture
{
	struct s_img	*no;
	struct s_img	*so;
	struct s_img	*ea;
	struct s_img	*we;
	char			*f;
	char			*c;
}	t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_dda
{
	int		win_width;
	int		win_height;
	double	camerax;
	double	plane_x;
	double	plane_y;
	double	raydirx;
	double	raydiry;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	sdist_x;
	double	sdist_y;
	double	ddist_x;
	double	ddist_y;
	double	perpWallDist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	char	**map;
}	t_dda;

typedef struct	s_line
{
	int	x;
	int	height;
	int	y;
	int	y0;
	int	y1;
	int	tex_x;
	int	tex_y;
}	t_line;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
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
int		ft_check_horizontal(char *line, int r, char **map);
int		ft_check_rest_rows(char **map, int row);
/* check_row.c */
int		ft_left_up(char **map, int r);
int		ft_left_down(char **map, int r);
int		ft_right_up(char **map, int r);
int		ft_right_down(char **map, int r);
int		ft_check_spaces(int x, int y, char **map);
/* get_cub_utils.c */
int		ft_get_colors(t_cube *cube);
void	ft_check_dir(t_player *player, char dir);

/***** GAME*****/
/* init.c */
void	init_game(t_cube *cube);
/* dda.c */
void	ft_init_dda(t_dda *dda, t_cube *cube);
void	ft_first_op(t_dda *dda, int x);
void	ft_calculate_side_dist(t_dda *dda);
void	ft_calculate_dda(t_dda *dda, char **map);

/* textures.c */
int	ft_init_textures(t_cube *cube);

/* ceiling_floor.c */
void	ft_floor(t_cube *cube);
void	ft_ceiling(t_cube *cube);
#endif