/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:59:35 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 16:27:03 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_pass_pixel(t_data *data1, double height,
						double wall_x_to_pic, double i)
{
	double		wall_y_to_pic;

	data1->pixel_y = data1->mid_screen - i;
	wall_y_to_pic = (data1->img_height[4] * (height / 2 - i)) / height;
	ft_print_pixel_from_xmp_sp(data1,
				data1->s_line_now + data1->off_set - (height / 2),
				wall_x_to_pic, wall_y_to_pic);
	data1->pixel_y = data1->mid_screen + i;
	wall_y_to_pic = (data1->img_height[4] * (height / 2 + i) / height);
	ft_print_pixel_from_xmp_sp(data1,
				data1->s_line_now + data1->off_set - (height / 2),
				wall_x_to_pic, wall_y_to_pic);
}
