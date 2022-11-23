/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:07:41 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/17 14:30:31 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "cub3d.h"
# define ESC_KEY 53
# define HEADER_SIZE 122

/*
**			*win	: Adress of windows
**			*mlx	: Adress of virtual scene (mlx)
**			*img	: Adress of the Image to ship
**			*addr	: Adress of
**			wxs		: Windows X Size
**			wys		: Windows Y Size
*/

typedef struct	s_vars_sp
{
	double		sx;
	double		sy;
	double		s_dis;
	double		s_dis_x;
	double		s_dis_y;
	float		s_ang;
	int			s_visible;
}				t_sprites;

typedef struct	s_vars
{
	int			save;
	void		*win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			wxs;
	int			wys;
	char		**map;
	int			map_max_y;
	int			map_biggest_x;

	int			i_m;
	int			is_player;
	char		c1;
	char		c2;

	int			entered_f;
	int			entered_c;
	int			entered_r;
	int			entered_no;
	int			entered_we;
	int			entered_ea;
	int			entered_so;
	int			entered_s;

	int			i_letters;
	int			f_color;
	int			c_color;

	int			size_tiles;

	double		px;
	double		py;
	int			move;
	int			lateral;
	int			rotate;
	double		angle;

	int			look_up;
	int			look_right;

	double		v_ray_hit_x;
	double		v_ray_hit_y;

	double		h_ray_hit_x;
	double		h_ray_hit_y;

	int			hitting_h;

	double		r_angle;
	int			r_look_up;
	int			r_look_right;

	double		y_to_plane;
	double		fov;
	double		fov_half;
	double		r_angle_increase;

	double		dis;

	double		mid_screen;
	double		off_set;
	int			s_line_now;
	int			ori;

	double		p_mid_screen;
	double		p_current_line;
	int			pixel_y;

	void		*img_t_addr[5];
	void		*img_t[5];
	char		*relative_path[5];
	int			img_width[5];
	int			img_height[5];
	int			t_bits_per_pixel[5];
	int			t_line_length[5];
	int			t_endian[5];

	int			num_sp;
	t_sprites	*arr_sp;
}				t_data;

/*
**				main.c
*/

int				ft_prepare_images(t_data *data1, char *str, int ori);
void			ft_paint_x(t_data *data1, int x_from, int x_to, int ori);
int				ft_number_of_args(t_data *data1, int argc, char *argv[]);

/*
**				ft_read.c
*/

int				ft_read(t_data *data1, char *argv[], int i);
int				ft_organize_map(t_data *data1, char *raw, int n_read);
int				ft_strn_cub(char *str);

/*
**				ft_map_info.c
*/

void			ft_find_max_y(t_data *data1);
void			ft_find_biggest_x(t_data *data1);
int				ft_find_player_start(t_data *data1, int i);
void			ft_clear_map(t_data *data1);
void			ft_find_n_sprites(t_data *data1);

/*
**				ft_img_handle.c
*/

int				ft_img_handle(t_data *data1);
void			ft_draw_half(t_data *data1, int begin_y, int end_y, int color);
void			ft_print_map(t_data *data1);
void			square(t_data *data1, int color, int x_given, int y_given);
void			square_smol(t_data *data1, int color, int x_given, int y_given);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_display_sprites(t_data *data1);

/*
**				ft_player.c
*/

void			ft_player(t_data *data1);
void			re_calculate_angle(t_data *data1);
int				ft_collision(t_data *data1, int forward);
int				ft_collision_late(t_data *data1, int forward);

/*
**				ft_player_ray.c
*/

void			ft_ray_battery(t_data *data1);
void			ft_wall_print_loop(t_data *data1, double wall_height,
				double *z_buff);
void			ft_draw_line_h(t_data *data1, int current_line, double height,
				double *z_buff);
void			ft_draw_line_v(t_data *data1, int current_line, double height,
				double *z_buff);
void			ft_print_pixel_from_xmp(t_data *data1, double x,
				double wall_x_to_pic, double wall_y_to_pic);
void			ft_print_pixel_from_xmp_sp(t_data *data1, double x,
				double wall_x_to_pic, double wall_y_to_pic);

/*
**				ft_player_pixel.c
*/

void			ft_player_find_pixel(t_data *data1, double wall_x_to_pic,
				double height, double i);

/*
**				ft_sprite.c
*/

void			ft_sprite_hub(t_data *data1, double wall_height,
				double *z_buff);
void			ft_s_visibility(t_data *data1, int n);
void			ft_print_sp(t_data *data1, double height, double *z_buff,
				int n);
void			ft_s_line_by_line(t_data *data1, int n);
void			ft_battery_sp(t_data *data1, double height, double *z_buff,
				int n);
void			ft_pass_pixel(t_data *data1, double height,
				double wall_x_to_pic, double i);

/*
**				ft_ray.c
*/

void			ft_look_direction(t_data *data1);
void			ft_ray(t_data *data1);

/*
**				ft_ray_h.c
*/

void			ft_find_hit_x(t_data *data1);
void			ft_detection_h_down(t_data *data1);
void			ft_detection_h_up(t_data *data1);

/*
**				ft_ray_v.c
*/

void			ft_find_hit_y(t_data *data1);
void			ft_detection_v_left(t_data *data1);
void			ft_detection_v_right(t_data *data1);

/*
**				hooks.c
*/

int				hook_press(int keycode, t_data *data1);
int				hook_release(int keycode, t_data *data1);
int				hook_cross(t_data *data1);

/*
**				ft_map_arg.c
*/

int				ft_map_collect_lines(t_data *data1, char *raw, int i);
int				ft_save_par(t_data *data1, char *raw, int i);
int				ft_valid_ch(char c);
int				ft_spaces_val(char *raw, int i);

/*
**				ft_map_cf.c
*/

int				ft_half_colors(t_data *data1, char *raw, char c, int i);
int				ft_conv_rgb(int num, int num_old, int round);
int				ft_half_colors(t_data *data1, char *raw, char c, int i);

/*
**				ft_map_res.c
*/

int				ft_resolution(t_data *data1, char *raw, int i, int j);
int				ft_check_good_res(t_data *data1, int i);

/*
**				ft_map_path.c
*/

int				ft_pass_path(t_data *data1, char *str);
int				ft_paths(t_data *data1, char *raw, int i);
int				ft_check_ident(t_data *data1, char *raw, int i);

/*
**				ft_error.c
*/

int				ft_error(int code);
void			ft_error_10s(int code);
void			ft_error_20s(int code);

/*
**				ft_save_bmp.c
*/

int				ft_save_bmp(t_data *data1);

/*
**				ft_map_check_good.c
*/

int				ft_map_check_good(t_data *data1);
int				ft_rows(char **str, int i, int j);
int				ft_columns(t_data *data1, char **str, int i, int j);
int				ft_check_mid_line_or_ch(char *raw, int i);
int				solo_hay_unos(t_data *data1, char **str, int i, int j);
int				no_unos(t_data *data1, char **str, int i, int j);

/*
**				Libft.c
*/

size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

#endif
