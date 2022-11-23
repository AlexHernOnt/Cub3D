/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:12:12 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 19:49:43 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_find_biggest_x(t_data *data1)
{
	int	i;
	int j;
	int	big;

	i = 0;
	j = 0;
	big = 0;
	while (data1->map[i] != '\0')
	{
		while (data1->map[i][j] != '\0')
			j++;
		if (j > big)
			big = j;
		j = 0;
		i++;
	}
	data1->map_biggest_x = big;
}

int			ft_p_ori_assigment(t_data *data1, char c)
{
	if (data1->is_player == 1)
		return (ft_error(15));
	if (c == 'N')
		data1->angle = 3 * M_PI / 2 + 0.000001;
	if (c == 'S')
		data1->angle = M_PI / 2 + 0.000001;
	if (c == 'E')
		data1->angle = 0.000001;
	if (c == 'W')
		data1->angle = M_PI + 0.000001;
	return (1);
}

int			ft_player_check_arr(t_data *data1, int j, int k)
{
	if (data1->map[j][k] != 'N' && data1->map[j][k] != 'S' &&
			data1->map[j][k] != 'W' && data1->map[j][k] != 'E' &&
			data1->map[j][k] != '1' && data1->map[j][k] != '0' &&
			data1->map[j][k] != ' ' && data1->map[j][k] != '2')
		return (ft_error(23));
	if (data1->map[j][k] == 'N' || data1->map[j][k] == 'W'
	|| data1->map[j][k] == 'S' || data1->map[j][k] == 'E')
	{
		if (ft_p_ori_assigment(data1, data1->map[j][k]) < 0)
			return (-1);
		data1->px = k * 50 + 20;
		data1->py = j * 50 + 20;
		data1->is_player = 1;
	}
	return (1);
}

int			ft_find_player_start(t_data *data1, int j)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (data1->map[j] != '\0')
	{
		while (data1->map[j][k] != '\0')
		{
			if (ft_player_check_arr(data1, j, k) < 0)
				return (-1);
			if (data1->map[j][k] == '2')
			{
				data1->arr_sp[n].sx = k * 50 + 25;
				data1->arr_sp[n].sy = j * 50 + 25;
				n++;
			}
			k++;
		}
		k = 0;
		j++;
	}
	if (data1->is_player == 0)
		return (ft_error(21));
	return (1);
}

void		ft_find_n_sprites(t_data *data1)
{
	int j;
	int k;
	int n;

	j = 0;
	k = 0;
	n = 0;
	while (data1->map[j] != '\0')
	{
		while (data1->map[j][k] != '\0')
		{
			if (data1->map[j][k] == '2')
				n++;
			k++;
		}
		k = 0;
		j++;
	}
	data1->num_sp = n;
	data1->arr_sp = malloc(n * sizeof(t_sprites));
}
