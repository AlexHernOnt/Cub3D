/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:37:16 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 16:54:25 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**				D I R E C T I O N
*/

void			ft_look_direction(t_data *data1)
{
	if (data1->r_angle > M_PI)
		data1->r_look_up = 1;
	else
		data1->r_look_up = 0;
	if (data1->r_angle < M_PI / 2 || data1->r_angle > M_PI + M_PI / 2)
		data1->r_look_right = 1;
	else
		data1->r_look_right = 0;
}

void			ft_ray(t_data *data1)
{
	ft_look_direction(data1);
	ft_find_hit_y(data1);
	ft_find_hit_x(data1);
	if (fabs((data1->h_ray_hit_x / cos(data1->r_angle))) <
	fabs((data1->v_ray_hit_x / cos(data1->r_angle))))
	{
		data1->hitting_h = 1;
		data1->dis = fabs((data1->h_ray_hit_x / cos(data1->r_angle)));
	}
	else
	{
		data1->hitting_h = 0;
		data1->dis = fabs((data1->v_ray_hit_x / cos(data1->r_angle)));
	}
}
