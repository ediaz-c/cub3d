/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:16:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/14 21:15:34 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CHARS_MAP	" 01NSEWDO"
# define CHARS_P	"NSEW"
# define WIN_H		720
# define WIN_W		1280
# define FOV		60
# define NORTH		1
# define SOUTH		1
# define EAST		0
# define WEST		0
/* MINIMAP */
# define MINI_WALL	0x00647C81 
# define MINI_FLOOR	0x22B9B9B9
# define MINI_PLAYER 0x00FF0000
# define SIZE_MINI 200
# define SIZE_WALL 24
# define TEXTURE_WIDHT 64
# define TEXTURE_HEIGHT 64
# define BG_COLOR 0x0025FF00
# define REFRESH 1
# define STOP 0

# define CEILING 0
# define FLOOR 1
# define DOOR_WALL 2
# define DOOR 3

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_dark_color
{
	int		r;
	int		g;
	int		b;
	double	factor;
	double	dist;
	double	max_dist;
}	t_dark_color;

typedef struct s_render_floor_and_ceiling
{
	int		x;
	int		y;
	int		floor_color;
	int		ceiling_color;
	int		*floor_buffer;
	int		f_index;
	int		*ceiling_buffer;
	int		c_index;
}	t_render_floor_and_ceiling;

typedef struct s_pos_int
{
	int	x;
	int	y;
}	t_pos_int;

typedef struct s_line_params
{
	int	end_x;
	int	end_y;
	int	step_x;
	int	step_y;
	int	error;
	int	dx;
	int	dy;
	int	x;
	int	y;
}	t_line_params;

typedef struct s_line
{
	int		draw_start;
	int		draw_end;
	int		x;
	int		y;
	int		y0;
	int		y1;
	int		tex_x;
	int		tex_y;
	int		line_height;
	char	wall_tex;
}	t_line;

typedef struct s_mini_walls
{
	t_pos		start;
	t_pos		iter;
	t_pos_int	map;
	int			pos;
	int			*buffer;
}	t_mini_walls;

typedef struct s_map
{
	int	w;
	int	h;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		pixel;
	int		height;
	int		width;
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
	t_map				data_map;
	struct s_minimap	*mini;
	struct s_player		*p;
	struct s_mlx		*mlx;
	struct s_texture	*txt;
	struct s_img		img;
	int					mouse_listen;
	t_pos				door_handler;
}	t_cube;

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
	int				bpp;
	int				size_line;
	int				endian;
	int				pixel;
	int				*buffer;
	struct s_player	player;
}	t_minimap;

typedef struct s_raysult
{
	int				side;
	int				hit;
	double			perp_wall_dist;
	double			camera_x;
	int				curent_col;
	int				current_row;
	t_pos			ray_dir;
	char			door_dir;
	int				is_door;
	int				door;
	t_pos			ray_dir0;
	t_pos			ray_dir1;
	int				screen_pos;
	double			pos_z;
	double			row_dist;
	t_pos			floor_step;
	t_pos			floor;
	t_pos_int		cell;
	t_pos_int		tex;
	t_pos			mpos;
	t_pos			side_dist;
	t_pos			delta_dist;
	t_pos			step;
	double			wall_x;
	struct s_line	*line;
	t_img			*texture;
}				t_raysult;

typedef struct s_texture
{
	struct s_img	no;
	struct s_img	so;
	struct s_img	ea;
	struct s_img	we;
	struct s_img	door_wall;
	struct s_img	door;
	struct s_img	floor;
	struct s_img	ceiling;
}	t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

#endif