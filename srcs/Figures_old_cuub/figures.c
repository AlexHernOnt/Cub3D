/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:27:24 by ahernand          #+#    #+#             */
/*   Updated: 2021/03/16 19:25:09 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_half(t_data *data1, int begin_y, int end_y, int color)
{
	int		x;
	int		y;

	x = 0;
	y = begin_y;
	while (x < data1->WXS)
	{
		while (y < end_y && y < data1->WYS)
		{
			my_mlx_pixel_put(data1, x, y, color);
			y++;
		}
		y = begin_y;
		x++;
	}
}


int		ft_print_map(t_data *data1)
{
	int j;
	int k;

	j = 0;
	k = 0;
/*
	while (data1->map[j] != '\0' && j * 50 < data1->WYS)
	{
		while (data1->map[j][k] && k * 50 < data1->WXS)
		{
			if (data1->map[j][k] == '0' || data1->map[j][k] == 'N' || data1->map[j][k] == '2')
				square(data1, 33023, k * 50, j * 50);
			else if (data1->map[j][k] == '1')
				square(data1, 16777215, k * 50, j * 50);
			else if (data1->map[j][k] == ' ')
				square(data1, 0, k * 50, j * 50);
			k++;
		}
		k = 0;
		j++;
	}
*/
//	ft_half(data1, 0, data1->WYS / 2, 5217241);	//	Orange sunset: 16493703);
//	ft_half(data1,data1->WYS / 2,  data1->WYS, 2263842);
	
	ft_player(data1);
	mlx_put_image_to_window(data1->mlx, data1->win, data1->img, 0, 0);
	mlx_do_sync(data1->mlx);
	return (0);
}

void		ft_draw_line(t_data *data1, int current_line, double height)
{
	int		i;
	int		mid_screen;

	i = 0;
	mid_screen = data1->WYS / 2;
	while (i < height / 2)
	{
		if (mid_screen - i > 0)
		{
			my_mlx_pixel_put(data1, current_line, mid_screen + i, 128);
			my_mlx_pixel_put(data1, current_line, mid_screen - i, 128);
		}
		i++;
	}
}

void		triangle(t_data *data1, int color)
{
	int		x;
	int		y;
	int		tri;

	x = 200;
	y = 200;
	my_mlx_pixel_put(data1, x, y, color);
	
	tri = 0;
	while (x < 600)
	{
		while (y < 600)
		{
			my_mlx_pixel_put(data1, x, y, color);
			y++;
		}
		tri++;
		y = 200 + tri;
		x++;
	}
	
}

void		ft_trial(t_data *data1, int color, int x, int y)
{
	int		tx;
	int		ty;

	tx = 1;
	ty = 1;

//	printf("pium");
//	fflush(0);

	while (ty < y)
	{
		while (tx < x)
		{
			my_mlx_pixel_put(data1, tx, ty, color);
			++tx;
		}
		tx = 0;
		++ty;
	}
}

void		square(t_data *data1, int color, int x_given, int y_given)
{
	int		x;
	int		y;

	x = x_given;
	y = y_given;
	while (x < x_given + 50)
	{
		while (y < y_given + 50)
		{
			my_mlx_pixel_put(data1, x, y, color);
			y++;
		}
		y = y_given;
		x++;
	}
}


void		square_smol(t_data *data1, int color, int x_given, int y_given)
{
	int		x;
	int		y;

	x = x_given;
	y = y_given;
	while (x < x_given + 10)
	{
		while (y < y_given + 10)
		{
			my_mlx_pixel_put(data1, x, y, color);
			y++;
		}
		y = y_given;
		x++;
	}
}


