/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_f_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:20:20 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/17 14:02:01 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_assign_color(t_data *data1, int num_old, char c, int i)
{
	if (c == 'C')
		data1->c_color = num_old;
	else if (c == 'F')
		data1->f_color = num_old;
	data1->i_letters++;
	return (i);
}

int			ft_conv_rgb(int num, int num_old, int round)
{
	if (num > 255)
		return (ft_error(10));
	if (round == 0)
		return (num * 256 * 256 + num_old);
	if (round == 1)
		return (num * 256 + num_old);
	if (round == 2)
		return (num + num_old);
	return (0);
}

int			ft_extra(char *raw, int num_old, int round, int *i)
{
	int		num;

	num = 0;
	while (raw[*i] != '\0' && round < 3)
	{
		while (raw[*i] != '\0' && (raw[*i] == ' ' || raw[*i] == ','))
			*i = *i + 1;
		while (raw[*i] != '\0' && (raw[*i] >= '0' && raw[*i] <= '9'))
		{
			num *= 10;
			num += raw[*i] - 48;
			*i = *i + 1;
		}
		if (raw[*i] != ' ' && raw[*i] != ',' && raw[*i] != '\n')
			return (ft_error(9));
		if (num == 0)
			num = 1;
		num_old = ft_conv_rgb(num, num_old, round);
		if (num_old < 0)
			return (-1);
		num = 0;
		round++;
	}
	return (num_old);
}

int			ft_half_colors(t_data *data1, char *raw, char c, int i)
{
	int		num_old;
	int		round;

	i++;
	round = 0;
	num_old = 0;
	num_old = ft_extra(raw, num_old, round, &i);
	if (num_old < 0)
		return (-1);
	if (raw[i] != '\n')
		return (ft_error(8));
	return (ft_assign_color(data1, num_old, c, i));
}
