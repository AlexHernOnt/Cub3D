/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_ray_battery.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:36:45 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 19:33:10 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**				Ray_battery						/ / / | | | \ \ \
*/

void			ft_ray_battery(t_data *data1)
{
	int			i;
	double		wall_height;
	double		*z_buff;

	i = 0;
	wall_height = 50;
	z_buff = malloc(data1->wxs * sizeof(double));
	data1->fov = M_PI / 3;
	data1->fov_half = data1->fov / 2;
	data1->r_angle_increase = (data1->fov / data1->wxs);
	data1->r_angle = (data1->angle) - data1->fov_half;
	data1->y_to_plane = (data1->wxs / 2) / tan(data1->fov_half);
	data1->mid_screen = data1->wys / 2;
	ft_wall_print_loop(data1, wall_height, z_buff);
	ft_sprite_hub(data1, wall_height, z_buff);
	free(z_buff);
	z_buff = NULL;
}

void			ft_wall_print_loop(t_data *data1, double wall_height,
				double *z_buff)
{
	double		final_len;
	int			i;

	i = 0;
	while (i < data1->wxs)
	{
		if (data1->r_angle >= M_PI * 2)
			data1->r_angle = 0.0000001 + (data1->r_angle - M_PI * 2);
		else if (data1->r_angle <= 0)
		{
			if (data1->r_angle > 0)
				data1->r_angle = 2 * M_PI + 0.0000001 - (data1->r_angle);
			else
				data1->r_angle = 2 * M_PI + 0.0000001 + (data1->r_angle);
		}
		ft_ray(data1);
		final_len = wall_height / (data1->dis *
				cosf(data1->r_angle - data1->angle)) * data1->y_to_plane;
		if (data1->hitting_h == 1)
			ft_draw_line_h(data1, i, final_len, z_buff);
		else
			ft_draw_line_v(data1, i, final_len, z_buff);
		data1->r_angle += data1->r_angle_increase;
		i++;
	}
}

/*
**				wall_y_to_pic: get the right pixel for the wall in Y
*/

void			ft_draw_line_h(t_data *data1, int current_line,
				double height, double *z_buff)
{
	double		i;
	double		wall_x;
	double		wall_x_to_pic;

	i = 0;
	data1->ori = 2;
	z_buff[current_line] = data1->dis;
	if (data1->r_look_up)
		data1->ori = 0;
	if (data1->r_look_right == 1)
		wall_x = fabs(fmod(data1->px + data1->h_ray_hit_x, 50));
	else
		wall_x = fabs(fmod(data1->px - data1->h_ray_hit_x, 50));
	wall_x_to_pic = wall_x * data1->img_width[data1->ori] / 50;
	data1->p_current_line = current_line;
	while (i < height / 2)
	{
		if (data1->mid_screen - i > 0)
			ft_player_find_pixel(data1, wall_x_to_pic, height, i);
		i++;
	}
}

void			ft_draw_line_v(t_data *data1, int current_line, double height,
				double *z_buff)
{
	double		i;
	double		wall_x;
	double		wall_x_to_pic;

	i = 0;
	data1->ori = 1;
	z_buff[current_line] = data1->dis;
	if (data1->r_look_right)
		data1->ori = 3;
	if (data1->r_look_up == 1)
		wall_x = fabs(fmod(data1->py - data1->v_ray_hit_y, 50));
	else
		wall_x = fabs(fmod(data1->py + data1->v_ray_hit_y, 50));
	wall_x_to_pic = wall_x * data1->img_width[data1->ori] / 50;
	data1->p_current_line = current_line;
	while (i < height / 2)
	{
		if (data1->mid_screen - i > 0)
			ft_player_find_pixel(data1, wall_x_to_pic, height, i);
		i++;
	}
}
