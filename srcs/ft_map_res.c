/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:30:38 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 14:22:39 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_good_res(t_data *data1, int i)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(data1->mlx, &max_x, &max_y);
	if (data1->wxs > max_x)
		data1->wxs = max_x;
	if (data1->wys > max_y)
		data1->wys = max_y;
	if (data1->wys < 10 || data1->wxs < 10)
		return (ft_error(22));
	data1->i_letters++;
	return (i);
}

int			ft_resolution(t_data *data1, char *raw, int i, int j)
{
	int		num;

	num = 0;
	while (j < 2)
	{
		while (raw[i] != '\0' && raw[i] == ' ')
			i++;
		while (raw[i] != '\0' && (raw[i] >= '0' && raw[i] <= '9'))
		{
			num *= 10;
			num += raw[i] - 48;
			i++;
		}
		if (raw[i] != ' ' && raw[i] != '\n')
			return (ft_error(7));
		if (j == 0)
			data1->wxs = num;
		else
			data1->wys = num;
		num = 0;
		j++;
	}
	if (raw[i] != '\n')
		return (ft_error(8));
	return (ft_check_good_res(data1, i));
}
