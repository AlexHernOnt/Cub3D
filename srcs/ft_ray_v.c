/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:48:56 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 17:03:53 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**				R A Y   C A S T   H E A V Y   L I F T I N G
**			         	 E P I S O D E   Y
*/

void	ft_find_hit_y(t_data *data1)
{
	if (data1->r_look_right == 1)
	{
		data1->v_ray_hit_x = (50 - 0.000001 - fmod(data1->px, 50));
	}
	else
	{
		data1->v_ray_hit_x = (fmod(data1->px, 50));
	}
	data1->v_ray_hit_y = data1->v_ray_hit_x *
	tan(data1->r_angle + 0.0000000001);
	if ((data1->r_look_up == 1 && data1->r_look_right == 1) ||
		(data1->r_look_right == 0 && data1->r_look_up == 0))
		data1->v_ray_hit_y *= -1;
	if (data1->r_look_right == 1)
		ft_detection_v_right(data1);
	else
		ft_detection_v_left(data1);
}

void	ft_detection_v_right(t_data *data1)
{
	if (data1->r_look_up == 1)
	{
		while ((int)((data1->py - data1->v_ray_hit_y) / 50) > 0 &&
		data1->map[(int)((data1->py - data1->v_ray_hit_y) / 50)]
		[(int)((data1->px + data1->v_ray_hit_x) / 50) + 1] != '1')
		{
			data1->v_ray_hit_x += 50;
			data1->v_ray_hit_y = data1->v_ray_hit_x * tan(data1->r_angle) *
			-1;
		}
	}
	else
	{
		while ((int)((data1->py + data1->v_ray_hit_y) / 50) <
		data1->map_max_y
		&& data1->map[(int)((data1->py + data1->v_ray_hit_y) / 50)]
		[(int)((data1->px + data1->v_ray_hit_x) / 50) + 1] != '1')
		{
			data1->v_ray_hit_x += 50;
			data1->v_ray_hit_y = (data1->v_ray_hit_x * tan(data1->r_angle));
		}
	}
}

void	ft_detection_v_left(t_data *data1)
{
	if (data1->r_look_up == 1)
	{
		while ((int)((data1->py - data1->v_ray_hit_y) / 50) > 0 &&
		data1->map[((int)(data1->py - data1->v_ray_hit_y) / 50)]
		[(int)((data1->px - data1->v_ray_hit_x) / 50) - 1] != '1')
		{
			data1->v_ray_hit_x += 50;
			data1->v_ray_hit_y = (data1->v_ray_hit_x * tan(data1->r_angle));
		}
	}
	else
	{
		while ((int)((data1->py + data1->v_ray_hit_y) / 50) <
		data1->map_max_y &&
		data1->map[((int)(data1->py + data1->v_ray_hit_y) / 50)]
		[(int)((data1->px - data1->v_ray_hit_x) / 50) - 1] != '1')
		{
			data1->v_ray_hit_x += 50;
			data1->v_ray_hit_y = (data1->v_ray_hit_x * tan(data1->r_angle) *
			-1);
		}
	}
}
