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
# include "keycodes.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/***** FREE *****/
/* free_str.c */
void		free_split(char **split);
/* free_cube.c */
void		ft_free_cube(t_cube *cube);

/***** MAP *****/
// Argument
int			ft_check_format(char *path, t_cube *cube);
/* check_map.c */
int			ft_check_chars(char **map);
void		ft_find_player(t_player *player, char **map);
int			ft_check_lines_empty(char **map);
int			ft_check_borders(t_player *p, char **map);
void		ft_fill_map(char **map);
/* get_cub.c */
void		ft_get_cube(t_cube *cube);
int			ft_check_map(t_cube *cube);
/* map_utils.c */
void		ft_size_map(t_cube *cube);
void		ft_change_chars(char **map, t_player *p);

/***** ERROR *****/
int			ft_exiterror(char *str);
int			ft_exiterror_cube(char *str, t_cube *cube);

/***** UTILS *****/
/* create_cube.c */
t_cube		*create_cube(t_cube **cube);
int			ft_search_elements(t_cube *cube, char *id, char *path);
int			ft_line_empty(char	*line);
char		**ft_fd_map(char *path, int fd);
/* check_map_utils.c */
char		**ft_cpy_matrix(char **matrix, char ***cpy_ptr);
int			ft_check_horizontal(char *line, int r, char **map);
int			ft_check_rest_rows(char **map, int row);
void		ft_dimensions_map(char **map, int *height, int *witdh);
/* check_row.c */
int			ft_left_up(char **map, int r);
int			ft_left_down(char **map, int r);
int			ft_right_up(char **map, int r);
int			ft_right_down(char **map, int r);
int			ft_check_spaces(int x, int y, char **map);
/* get_cub_utils.c */
int			ft_get_colors(t_cube *cube);
void		ft_check_dir(t_player *player, char dir);
/* pos.c */
void		set_pos(t_pos *pos, double x, double y);
void		cpy_pos(t_pos *pos1, t_pos *pos2);
/* raycasting_utils.c */
void		calculate_xcamera(t_cube *cube);

/***** GAME*****/
/* init.c */
void		init_game(t_cube *cube);

/* textures.c */
int			ft_init_textures(t_cube *cube);

/* close.c */
int			ft_close(int k, t_mlx *mlx);

/* loop.c */
int			loop(t_cube *cube);
/* raycasting.c */
void		raycasting(t_cube *cube);

/* player.c */
void		ft_init_player(t_cube *cube);

/* handler_key.c */
int			ft_keypress(int keycode, t_cube *cube);
void		ft_handler_move(int keycode, t_cube *cube);
void		ft_handler_rotate(int keycode, t_cube *cube);

/* move.c */
void		ft_move_up(t_cube *cube, t_player *p, char **map);
void		ft_move_down(t_cube *cube, t_player *p, char **map);
void		ft_move_left(t_cube *cube, t_player *p, char **map);
void		ft_move_right(t_cube *cube, t_player *p, char **map);

/* rotate.c */
void		ft_rotate_left(t_cube *cube, double rot_speed);
void		ft_rotate_right(t_cube *cube, double rot_speed);

/* handler_mouse.c */
int			ft_mouse(int button, int x, int y, t_cube *cube);
void		mouse_listening(t_cube *cube);

/***** MINIMAP *****/
/* minimap.c */
t_minimap	*ft_init_minimap(t_cube *cube, t_minimap **mini);
void		add_mini_walls(t_cube *cube, t_minimap *mini);
void		clean_minimap(t_cube *cube, t_minimap *mini);

/* player_minimap.c */
void		add_mini_player(t_cube *cube, t_minimap *mini);

#endif