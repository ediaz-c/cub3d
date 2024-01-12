/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:16:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2024/01/11 12:26:26 by ediaz--c         ###   ########.fr       */
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
# define MINI_FLOOR	0x00B9B9B9
# define MINI_PLAYER 0x00FF0000
# define SIZE_MINI 200
# define SIZE_WALL 24
# define TEXTURE_WIDHT 64
# define TEXTURE_HEIGHT 64
# define BG_COLOR 0x0025FF00

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_pos_int
{
	int	x;
	int	y;
}	t_pos_int;

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

typedef struct s_line
{
	int		draw_start;
	int		draw_end;
	int		x; //the x coordinate of line relative to screen
	int		y; //the current pixel index of the line (along y axis)
	int		y0; //y start index of drawing texture
	int		y1; //y end index of drawing texture
	int		tex_x; //x coordinate of texture to draw
	int		tex_y; //y coordinate of texture to draw
	int		line_height;
	char	wall_tex;
}	t_line;

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
	struct s_player player;
}	t_minimap;

typedef struct	s_raysult
{
	int			side;
	int			hit;
	double		perp_wall_dist;
	double		camera_x;
	int			curent_col;
	int			current_row;
	t_pos		ray_dir;
	char		door_dir;	//BONUS
	int			is_door;	//BONUS
	int			door;		//BONUS
	t_pos 		ray_dir0;	//BONUS
	t_pos 		ray_dir1;	//BONUS
	int			screen_pos;	//BONUS
	double		pos_z;		//BONUS
	double		row_dist;	//BONUS
	t_pos		floor_step;	//BONUS
	t_pos		floor;		//BONUS
	t_pos_int	cell;		//BONUS
	t_pos_int	tex;		//BONUS
	t_pos		mpos;
	t_pos		side_dist;
	t_pos		delta_dist;
	t_pos		step;
	double		wall_x;
	struct s_line	*line;
	t_img		*texture;
}				t_raysult;

typedef struct	s_texture
{
	struct s_img	no;
	struct s_img	so;
	struct s_img	ea;
	struct s_img	we;
	struct s_img	door_wall;	//BONUS
	struct s_img	door;		//BONUS
	struct s_img	floor;		//BONUS
	struct s_img	ceiling;	//BONUS
}	t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

# endif