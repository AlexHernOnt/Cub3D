/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_good_rc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:39:13 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 11:48:30 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_liner(char **str, int i, int j)
{
	j = 0;
	while (str[i][j] != '\0')
	{
		if (str[i][j] != '1' && str[i][j] != ' ')
			return (-1);
		j++;
	}
	return (1);
}

int			ft_rows(char **str, int i, int j)
{
	int		wall;

	i = 1;
	wall = 0;
	while (str[i] != '\0')
	{
		while (str[i][j] != '\0')
		{
			if ((str[i][j] == ' ' && wall == 1 && ft_liner(str, i, j) < 0) ||
			(str[i][j] == '0' && wall != 1))
				return (ft_error(17));
			if (str[i][j] == '1' && (wall == 0 || wall == 2))
				wall = 1;
			else if (str[i][j] == '1' && wall == 1
			&& (str[i][j + 1] == '\0' || str[i][j + 1] == ' '))
				wall = 2;
			j++;
		}
		if (wall < 2 && ft_liner(str, i, j) < 0)
			return (ft_error(17));
		wall = 0;
		j = 0;
		i++;
	}
	return (1);
}

int			ft_col_empty(t_data *data1, char **str, int i, int j)
{
	i = 0;
	while (i < data1->map_max_y + 1)
	{
		if (str[i][j] != '1' && str[i][j] != ' ')
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_col_empty_mid(t_data *data1, char **str, int i, int j)
{
	while (i < data1->map_max_y + 1)
	{
		if (str[i][j] != '1' && str[i][j] != ' ')
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_columns(t_data *data1, char **str, int i, int j)
{
	int		wall;

	wall = 0;
	while (j < data1->map_biggest_x)
	{
		while (i < data1->map_max_y + 1)
		{
			if ((str[i][j] == ' ' && wall == 1 && no_unos(data1, str, i, j)
			> 0) || (str[i][j] == '0' && wall != 1))
				return (ft_error(18));
			if (str[i][j] == '1' && (wall == 0 || wall == 2)
			&& (!solo_hay_unos(data1, str, i, j)))
				wall = 1;
			else if (str[i][j] == '1' && wall == 1
			&& (str[i + 1][j] == '\0' || str[i + 1][j] == ' '))
				wall = 2;
			i++;
		}
		if (wall < 2 && ft_col_empty(data1, str, i, j) < 0)
			return (ft_error(18));
		wall = 0;
		i = 0;
		j++;
	}
	return (1);
}
