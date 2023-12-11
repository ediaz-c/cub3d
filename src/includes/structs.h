/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:16:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/12/09 02:37:26 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CHARS_MAP	" 01NSEW"
# define CHARS_P	"NSEW"
# define WIN_H		750
# define WIN_W		1200
# define FOV		60

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
}	t_cube;

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
	t_pos			mpos;
	t_pos			side_dist;
	t_pos			delta_dist;
	t_pos			step;
	double			wall_x;
	struct s_line	*line;
}				t_raysult;

typedef struct s_texture
{
	struct s_img	no;
	struct s_img	so;
	struct s_img	ea;
	struct s_img	we;
}	t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;
#endif