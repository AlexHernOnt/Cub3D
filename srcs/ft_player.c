/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:40:31 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/11 15:41:25 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**				A N G L E
*/

void			ft_player(t_data *data1)
{
	if (data1->move == 1)
		if (ft_collision(data1, 1) == 0)
		{
			data1->px += cos(data1->angle) * 2;
			data1->py += sin(data1->angle) * 2;
		}
	if (data1->move == -1)
		if (ft_collision(data1, -1) == 0)
		{
			data1->px += cos(data1->angle) * -2;
			data1->py += sin(data1->angle) * -2;
		}
	if (data1->lateral == 1)
		if (ft_collision_late(data1, 1) == 0)
		{
			data1->px += cos(data1->angle + M_PI / 2) * 2;
			data1->py += sin(data1->angle + M_PI / 2) * 2;
		}
	if (data1->lateral == -1)
		if (ft_collision_late(data1, -1) == 0)
		{
			data1->px += cos(data1->angle - M_PI / 2) * 2;
			data1->py += sin(data1->angle - M_PI / 2) * 2;
		}
	re_calculate_angle(data1);
}

void			re_calculate_angle(t_data *data1)
{
	if (data1->angle >= M_PI * 2)
		data1->angle = 0.00001;
	else if (data1->angle <= 0)
		data1->angle = 2 * M_PI + 0.0000001;
	if (data1->rotate == 1)
		data1->angle -= (M_PI / 180) * 2;
	if (data1->rotate == -1)
		data1->angle += (M_PI / 180) * 2;
	ft_ray_battery(data1);
}

int				ft_collision(t_data *data1, int forward)
{
	double		x;
	double		y;

	x = fabs(data1->px + (cos(data1->angle) * 3 * forward)) / 50;
	y = fabs(data1->py + (sin(data1->angle) * 3 * forward)) / 50;
	if (x < 0 || y < 0 || data1->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int				ft_collision_late(t_data *data1, int forward)
{
	double		x;
	double		y;

	x = fabs(data1->px + (cos(data1->angle + M_PI / 2) * 3 * forward)) / 50;
	y = fabs(data1->py + (sin(data1->angle + M_PI / 2) * 3 * forward)) / 50;
	if (x < 0 || y < 0 || data1->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}
