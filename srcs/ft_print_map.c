/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:54:04 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 17:31:26 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**		Fts for Map Printing
*/

void		ft_print_map_sqaures(t_data *data1, int j, int k)
{
	if (data1->map[j][k] == '0' || data1->map[j][k] == 'N' ||
		data1->map[j][k] == 'W' || data1->map[j][k] == 'S' ||
		data1->map[j][k] == '2' || data1->map[j][k] == 'E')
		square(data1, 33023, k * 10, j * 10);
	else if (data1->map[j][k] == '1')
		square(data1, 16777215, k * 10, j * 10);
	else if (data1->map[j][k] == ' ')
		square(data1, 0, k * 10, j * 10);
}

void		ft_print_map(t_data *data1)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (data1->map[j] != '\0')
	{
		while (data1->map[j][k] != '\0')
		{
			ft_print_map_sqaures(data1, j, k);
			k++;
		}
		if (k < data1->map_biggest_x)
			while (k < data1->map_biggest_x)
			{
				square(data1, 16777215, k * 10, j * 10);
				++k;
			}
		k = 0;
		j++;
	}
	square_smol(data1, 132, data1->px / 5, data1->py / 5);
	ft_display_sprites(data1);
}

void		ft_display_sprites(t_data *data1)
{
	int		i;

	i = 0;
	while (i < data1->num_sp)
	{
		square_smol(data1, 1331132, data1->arr_sp[i].sx / 5,
					data1->arr_sp[i].sy / 5);
		i++;
	}
}

void		square(t_data *data1, int color, int x_given, int y_given)
{
	int		x;
	int		y;

	x = x_given;
	y = y_given;
	while (x < x_given + 10)
	{
		while (y < y_given + 10)
		{
			if (y < data1->wys / 3)
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
	while (x < x_given + 2)
	{
		while (y < y_given + 2)
		{
			if (y < data1->wys / 3)
				my_mlx_pixel_put(data1, x, y, color);
			y++;
		}
		y = y_given;
		x++;
	}
}
