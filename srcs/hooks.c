/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:11:44 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/15 20:01:07 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hook_release(int keycode, t_data *data1)
{
	if ((keycode == 0 && data1->lateral != 1)
			|| (keycode == 2 && data1->lateral != -1))
		data1->lateral = 0;
	if (keycode == 13 || keycode == 1)
		data1->move = 0;
	if ((keycode == 123 && data1->rotate != -1)
			|| (keycode == 124 && data1->rotate != 1))
		data1->rotate = 0;
	return (0);
}

int		hook_press(int keycode, t_data *data1)
{
	if (keycode == 53)
	{
		free(data1->arr_sp);
		exit(0);
	}
	if (keycode == 13)
		data1->move = 1;
	if (keycode == 1)
		data1->move = -1;
	if (keycode == 123)
		data1->rotate = 1;
	if (keycode == 124)
		data1->rotate = -1;
	if (keycode == 0)
		data1->lateral = -1;
	if (keycode == 2)
		data1->lateral = 1;
	return (keycode);
}

int		hook_cross(t_data *data1)
{
	free(data1->arr_sp);
	exit(0);
	return (0);
}

/*
**	system("leaks cub3D");
*/
