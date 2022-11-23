/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:53:18 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 19:28:42 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_img_handle(t_data *data1)
{
	ft_draw_half(data1, 0, data1->wys / 2, data1->c_color);
	ft_draw_half(data1, data1->wys / 2, data1->wys, data1->f_color);
	ft_player(data1);
	if (data1->wys > 500 && data1->wxs > 500)
		ft_print_map(data1);
	if (data1->save == 1)
		ft_save_bmp(data1);
	mlx_put_image_to_window(data1->mlx, data1->win, data1->img, 0, 0);
	mlx_do_sync(data1->mlx);
	return (0);
}

/*
**			fts draw 3d stuff
*/

void		ft_draw_half(t_data *data1, int begin_y, int end_y, int color)
{
	int		x;
	int		y;

	x = 0;
	y = begin_y;
	while (x < data1->wxs)
	{
		while (y < end_y && y < data1->wys)
		{
			my_mlx_pixel_put(data1, x, y, color);
			y++;
		}
		y = begin_y;
		x++;
	}
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && color > 0 && x < data->wxs)
	{
		dst = data->addr + (y * data->line_length + x *
							(data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void		ft_paint_x(t_data *data1, int x_from, int x_to, int ori)
{
	int		i;
	char	*dst;

	i = 0;
	while (i < data1->img_height[ori] && i < data1->wys)
	{
		dst = data1->img_t_addr[ori] + (i * data1->t_line_length[ori]
				+ x_from * (data1->t_bits_per_pixel[ori] / 8));
		my_mlx_pixel_put(data1, x_to, i, *(unsigned int*)dst);
		i++;
	}
}
