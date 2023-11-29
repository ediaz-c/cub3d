/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:16:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/11/29 20:23:55 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CHARS_MAP	" 01NSEW"
# define CHARS_P	"NSEW"
# define WIN_H		750
# define WIN_W		1200
# define FOV		60
/* MINIMAP */
# define MINI_WALL	0x00647C81 
# define MINI_FLOOR	0x00B9B9B9
# define MINI_PLAYER 0x00FF0000
# define SIZE_MINI 200
# define SIZE_WALL 24

typedef struct s_line_params
{
	int end_x;
	int end_y;
	int step_x;
	int step_y;
	int error;
	int dx;
	int dy;
	int x;
	int y;
}	t_line_params;

typedef struct	s_mini_walls
{
	double	start_x;
	double	start_y;
	double	i;
	double	j;
	int		map_x;
	int		map_y;
}	t_mini_walls;

typedef struct s_map
{
	int	w;
	int	h;
}	t_map;

typedef struct	s_img
{
	void	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;
	int		*buffer;
}	t_img;

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
	int					octal_c;
	int					octal_f;
	int					first_line;
	int					run;
	double				camera_x[WIN_W];
	t_map				data_map;
	struct s_minimap	*mini;
	struct s_player		*p;
	struct s_mlx		*mlx;
	struct s_texture	*txt;
	int					mouse_listen;
}	t_cube;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_player
{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
	t_img	img;
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_minimap
{
	int				height;
	int				width;
	t_pos			p;
	void			*img;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				pixel;
	int				*buffer;
	struct s_player player;
}	t_minimap;

typedef struct	s_raysult
{
	int			column;
	int			row;
	double		distance;
	int			direction;
	int			side;
	int			height;
	t_pos		ray_pos;
	t_pos		ray_dir;
	t_pos		map_pos;
	t_pos		side_dist;
	t_pos		delta_dist;
	t_pos		step;
	double		wall_x;
	t_pos		floor_wall;
	t_pos		c_floor;
}				t_raysult;

typedef struct	s_xpm
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}	t_xpm;

typedef struct	s_texture
{
	struct s_xpm	no;
	struct s_xpm	so;
	struct s_xpm	ea;
	struct s_xpm	we;
	struct s_img	cei;
	struct s_img	flo;
}	t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;


# endif