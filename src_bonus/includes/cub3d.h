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
# include "../../libs/libft/includes/libft.h"
# include "../../libs/mlx/mlx.h"
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
/*
*	- Open the file and save the content in a matrix
*	- Check if the elements are valids
*	- Check if the map is valid
*/
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
void		set_pos_int(t_pos_int *pos, int x, int y);
void		cpy_pos_int(t_pos_int *pos1, t_pos_int *pos2);
/* raycasting_operations_wall.c */
void		ft_calculate_ray_and_dist(t_raysult *ray, t_player *p, int x);
void		ft_calculate_step(t_raysult *ray, t_player *p);
char		ft_dda(t_cube *cube, t_raysult *ray);
void		ft_calculate_wall_dist(t_raysult *ray, t_cube *cube);
/* raycasting_draw_line.c */
void		ft_caltulate_line(t_line *line, t_raysult *ray);
void		ft_calculate_texture_x(t_cube *cube, t_line *line, t_raysult *ray);
void		ft_paint_pixels(t_cube *cube, t_line *line, t_raysult *ray, int x);
/* check_hit.c */
int			ft_check_hit_wall(t_cube *cube, t_raysult *ray);
int			ft_check_hit_door(t_cube *cube, t_raysult *ray);
/* my_mlx.c*/
void	my_img_pixel_put(t_img *img, int x, int y, int color);
/***** GAME*****/
/* game.c */
void		game(t_cube *cube);

/* textures.c */
int			ft_init_textures(t_cube *cube);

/* close.c */
int			ft_close(int k, t_mlx *mlx);

/* loop.c */
int			render(t_cube *cube);
/* raycasting.c */
void		raycasting(t_cube *cube);
void		my_img_pixel_put(t_img *img, int x, int y, int color);
void		ft_render_floor_and_ceiling(t_cube *cube, t_raysult *ray, t_player *p);
int			ft_dark_color_wall(t_raysult *ray, int color);
void		ft_check_is_door(t_cube *cube, t_raysult *ray);
/* player.c */
void		ft_init_player(t_cube *cube);

/* handler_key.c */
int			ft_keypress(int keycode, t_cube *cube);
void		ft_handler_move(int keycode, t_cube *cube);
void		ft_handler_rotate(int keycode, t_cube *cube);
int			ft_keyrelease(int keycode, t_cube *cube);

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
void		clean_minimap(t_minimap *mini);

/* player_minimap.c */
void		add_mini_player(t_cube *cube, t_minimap *mini);

/* MAIN */
/*
*	Check if the arguments are valids
*	- If the number of arguments is different than 2 exit with error
*	- If the extension is different than .cub exit with error
*/
void	ft_check_args(int ac, char *av[], t_cube **cube);
#endif