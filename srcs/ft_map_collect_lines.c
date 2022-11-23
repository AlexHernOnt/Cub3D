/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_collect_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:51:40 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 19:21:50 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**			Checker
*/

int			ft_map_collect_lines(t_data *data1, char *raw, int i)
{
	while (raw[i] != '\0' && (raw[i] == '\n' || ft_valid_ch(raw[i])))
	{
		if (raw[i] != '\n')
			i = ft_save_par(data1, raw, i);
		if (i < 0)
			return (-1);
		i++;
	}
	if (raw[i] != '\0' && raw[i] != '1' && raw[i] != '0' &&
								raw[i] != '2' && raw[i] != ' ')
		return (ft_error(16));
	if (data1->i_letters < 8)
		return (ft_error(6));
	if (ft_check_mid_line_or_ch(raw, i) < 0)
		return (-1);
	data1->map = ft_split(&raw[i], '\n');
	ft_find_biggest_x(data1);
	ft_find_max_y(data1);
	if (ft_map_check_good(data1) < 0)
		return (-1);
	return (1);
}

int			ft_save_par(t_data *data1, char *raw, int i)
{
	int		j;

	j = 0;
	if (raw[i] == 'R')
		i = ft_resolution(data1, raw, ++i, j);
	else if (raw[i] == 'F' || raw[i] == 'C')
		i = ft_half_colors(data1, raw, raw[i], i);
	else if (raw[i] == 'N' || raw[i] == 'S' || raw[i] == 'W' || raw[i] == 'E')
		i = ft_check_ident(data1, raw, i);
	data1->c1 = 0;
	data1->c2 = 0;
	if (i < 0)
		return (-1);
	return (i);
}

int			ft_valid_ch(char c)
{
	if (c == 'R' || c == 'F' || c == 'C' || c == 'N' || c == 'S' || c == 'W' ||
		c == 'E')
	{
		return (1);
	}
	return (0);
}

int			ft_check_mid_line_or_ch(char *raw, int i)
{
	while (raw[i] != '\0')
	{
		if (raw[i] != '0' && raw[i] != '1' && raw[i] != '2' && raw[i] != 'N'
		&& raw[i] != 'S' && raw[i] != 'E' && raw[i] != 'W' && raw[i] != '0' &&
		(raw[i] == '\n' && raw[i + 1] == '\n'))
			return (ft_error(19));
		i++;
	}
	if (raw[i - 1] == '\n')
		return (ft_error(19));
	return (1);
}

/*
**	printf("_RX  %d | RY %d.\n",	data1->wxs, data1->wys);
**	printf("_C   %d.\n",			data1->c_color);
**	printf("_F   %d.\n",			data1->f_color);
**	printf("_NO  %d.\n",			data1->img_width[0]);
**	printf("_WE  %d.\n",			data1->img_width[1]);
**	printf("_SO  %d.\n",			data1->img_width[2]);
**	printf("_EA  %d.\n",			data1->img_width[3]);
**	printf("_S   %d.\n",			data1->img_width[4]);
**	printf("i latst = %d\n",		i);
*/
