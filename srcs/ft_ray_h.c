/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:42:42 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 16:53:37 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**				R A Y   C A S T   H E A V Y   L I F T I N G
**			         	 E P I S O D E   X
*/

void	ft_find_hit_x(t_data *data1)
{
	if (data1->r_look_up == 1)
	{
		data1->h_ray_hit_y = (fmod(data1->py, 50));
	}
	else
	{
		data1->h_ray_hit_y = (50 - 0.000001 - fmod(data1->py, 50));
	}
	data1->h_ray_hit_x = data1->h_ray_hit_y /
		(tan(data1->r_angle + 0.000000001));
	if ((data1->r_look_right == 1 && data1->r_look_up == 1) ||
		(data1->r_look_right == 0 && data1->r_look_up == 0))
		data1->h_ray_hit_x *= -1;
	if (data1->r_look_up == 1)
		ft_detection_h_up(data1);
	else
		ft_detection_h_down(data1);
}

void	ft_detection_h_up(t_data *data1)
{
	if (data1->r_look_right == 1)
	{
		while ((size_t)((data1->px + data1->h_ray_hit_x) / 50) <
		ft_strlen(data1->map[(size_t)(data1->py - data1->h_ray_hit_y) / 50]) &&
		(data1->map[(int)((data1->py - data1->h_ray_hit_y) / 50) - 1]
		[(int)((data1->px + data1->h_ray_hit_x) / 50)] != '1'))
		{
			data1->h_ray_hit_y += 50;
			data1->h_ray_hit_x = (data1->h_ray_hit_y / tan(data1->r_angle)) *
			-1;
		}
	}
	else
	{
		while ((data1->px - data1->h_ray_hit_x > 0) &&
		(data1->map[(int)((data1->py - data1->h_ray_hit_y) / 50) - 1]
		[(int)((data1->px + data1->h_ray_hit_x * (-1)) / 50)] != '1'))
		{
			data1->h_ray_hit_y += 50;
			data1->h_ray_hit_x = (data1->h_ray_hit_y / tan(data1->r_angle));
		}
	}
}

void	ft_detection_h_down(t_data *data1)
{
	if (data1->r_look_right == 1)
	{
		while ((size_t)((data1->px + data1->h_ray_hit_x) / 50) <
		ft_strlen(data1->map[(size_t)(data1->py + data1->h_ray_hit_y) / 50]) &&
		data1->map[((int)(data1->py + data1->h_ray_hit_y) / 50) + 1]
		[(int)((data1->px + data1->h_ray_hit_x) / 50)] != '1')
		{
			data1->h_ray_hit_y += 50;
			data1->h_ray_hit_x = (data1->h_ray_hit_y / tan(data1->r_angle));
		}
	}
	else
	{
		while ((data1->px - data1->h_ray_hit_x) > 0 &&
		data1->map[((int)(data1->py + data1->h_ray_hit_y) / 50) + 1]
		[(int)((data1->px - data1->h_ray_hit_x) / 50)] != '1')
		{
			data1->h_ray_hit_y += 50;
			data1->h_ray_hit_x = data1->h_ray_hit_y / tan(data1->r_angle)
			* -1;
		}
	}
}
