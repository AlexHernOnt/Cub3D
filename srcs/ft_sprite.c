/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:50:05 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 11:41:13 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sort_sp(t_data *data1, int size, int *arr_o, int i)
{
	int		c;
	int		aux;

	c = 0;
	while (i < size)
	{
		arr_o[i] = i;
		i++;
	}
	i = 0;
	while (c < size)
	{
		while (i < size)
		{
			if (data1->arr_sp[arr_o[i]].s_dis > data1->arr_sp[arr_o[c]].s_dis)
			{
				aux = arr_o[c];
				arr_o[c] = arr_o[i];
				arr_o[i] = aux;
			}
			i++;
		}
		c++;
		i = c;
	}
}

void		ft_sprite_hub(t_data *data1, double wall_height, double *z_buff)
{
	int		n;
	int		i;
	int		*arr_o;

	n = 0;
	i = 0;
	arr_o = malloc(data1->num_sp * sizeof(int));
	while (n < data1->num_sp)
	{
		ft_s_visibility(data1, n);
		n++;
	}
	ft_sort_sp(data1, data1->num_sp, arr_o, i);
	while (i < data1->num_sp)
	{
		if (data1->arr_sp[arr_o[i]].s_visible == 1)
			ft_print_sp(data1, wall_height, z_buff, arr_o[i]);
		i++;
	}
	free(arr_o);
	arr_o = NULL;
}

void		ft_s_visibility(t_data *data1, int n)
{
	double	dif_ang;

	data1->arr_sp[n].s_visible = 0;
	data1->arr_sp[n].s_dis_x = data1->px - data1->arr_sp[n].sx;
	data1->arr_sp[n].s_dis_y = data1->py - data1->arr_sp[n].sy;
	data1->arr_sp[n].s_ang = atan2(data1->arr_sp[n].s_dis_y, data1->arr_sp[n].
																	s_dis_x);
	if (data1->arr_sp[n].s_ang < 0)
		data1->arr_sp[n].s_ang = M_PI + (M_PI - fabs(data1->arr_sp[n].s_ang));
	data1->arr_sp[n].s_dis =
						data1->arr_sp[n].s_dis_x / cos(data1->arr_sp[n].s_ang);
	data1->arr_sp[n].s_ang = fmod(data1->arr_sp[n].s_ang + M_PI, 2 * M_PI);
	dif_ang = data1->angle - data1->arr_sp[n].s_ang;
	if (dif_ang < -1 * M_PI)
		dif_ang += 2 * M_PI;
	if (dif_ang > M_PI)
		dif_ang -= 2 * M_PI;
	dif_ang = fabs(dif_ang);
	if (dif_ang < data1->fov_half + 1)
		data1->arr_sp[n].s_visible = 1;
}

void		ft_print_sp(t_data *data1, double height, double *z_buff, int n)
{
	double	wall_x;

	wall_x = 0;
	data1->s_line_now = 0;
	data1->mid_screen = data1->wys / 2;
	data1->off_set = (data1->wxs / 2) + tan((atan2(data1->arr_sp[n].s_dis_y,
					data1->arr_sp[n].s_dis_x) - data1->angle)) * data1->wxs;
	height = 50 / (data1->arr_sp[n].s_dis * cosf(data1->r_angle - data1->angle))
					* ((data1->wxs / 2) / tan(data1->fov_half));
	ft_battery_sp(data1, height, z_buff, n);
}

void		ft_battery_sp(t_data *data1, double height, double *z_buff, int n)
{
	double	i;
	double	wall_x_to_pic;

	i = 0;
	while (data1->s_line_now < height)
	{
		wall_x_to_pic = data1->s_line_now * data1->img_width[4] / height;
		if (data1->arr_sp[n].s_dis <
			z_buff[data1->s_line_now + (int)(data1->off_set - (height / 2))])
		{
			while (i < height / 2)
			{
				if (data1->mid_screen - i > 0)
				{
					ft_pass_pixel(data1, height, wall_x_to_pic, i);
				}
				i++;
			}
		}
		data1->s_line_now++;
		i = 0;
	}
}
