/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:45:11 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 16:28:05 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_player_find_pixel(t_data *data1, double wall_x_to_pic,
				double height, double i)
{
	double		wall_y_to_pic;

	data1->pixel_y = data1->mid_screen - i;
	wall_y_to_pic = (data1->img_height[data1->ori] * (height / 2 - i)) / height;
	ft_print_pixel_from_xmp(data1,
					data1->p_current_line, wall_x_to_pic, wall_y_to_pic);
	data1->pixel_y = data1->mid_screen + i;
	wall_y_to_pic = (data1->img_height[data1->ori] * (height / 2 + i) / height);
	ft_print_pixel_from_xmp(data1,
					data1->p_current_line, wall_x_to_pic, wall_y_to_pic);
}

void			ft_print_pixel_from_xmp(t_data *data1, double x,
				double wall_x_to_pic, double wall_y_to_pic)
{
	char		*dst;
	int			i;

	if (data1->hitting_h == 0 && data1->r_look_right == 1)
		i = 3;
	else if (data1->hitting_h == 0 && data1->r_look_right == 0)
		i = 1;
	else if (data1->hitting_h == 1 && data1->r_look_up == 1)
		i = 0;
	else
		i = 2;
	dst = data1->img_t_addr[i] + ((int)wall_y_to_pic * data1->t_line_length[i] +
				(int)wall_x_to_pic * (data1->t_bits_per_pixel[i] / 8));
	my_mlx_pixel_put(data1, x, data1->pixel_y, *(unsigned int*)dst);
}

void			ft_print_pixel_from_xmp_sp(t_data *data1, double x,
				double wall_x_to_pic, double wall_y_to_pic)
{
	char		*dst;
	int			i;

	i = 4;
	dst = data1->img_t_addr[i] + ((int)wall_y_to_pic * data1->t_line_length[i] +
				(int)wall_x_to_pic * (data1->t_bits_per_pixel[i] / 8));
	my_mlx_pixel_put(data1, x, data1->pixel_y, *(unsigned int*)dst);
}
