/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_good.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:07:01 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 11:40:13 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_copy_str(t_data *data1, char **n_str, int i, int j)
{
	while (data1->map[i])
	{
		while (data1->map[i][j] != '\0')
		{
			n_str[i + 1][j] = data1->map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
}

char		**ft_correct_arr(t_data *data1, int i, int j)
{
	char	**n_str;

	n_str = (char**)malloc(sizeof(char*) * (data1->map_max_y + 1 + 1 + 1));
	n_str[data1->map_max_y + 2] = 0;
	while (i < data1->map_max_y + 2)
	{
		n_str[i] = (char*)malloc(sizeof(char) * (data1->map_biggest_x + 1));
		n_str[i][data1->map_biggest_x] = '\0';
		i++;
	}
	i = 0;
	while (i < data1->map_max_y + 2)
	{
		while (j < data1->map_biggest_x)
		{
			n_str[i][j] = ' ';
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	ft_copy_str(data1, n_str, i, j);
	return (n_str);
}

int			ft_map_check_good(t_data *data1)
{
	int		i;
	int		j;
	int		res;
	char	**str;

	i = 0;
	j = 0;
	res = 1;
	str = ft_correct_arr(data1, i, j);
	if (ft_rows(str, i, j) < 0)
		res = -1;
	else if (ft_columns(data1, str, 1, j) < 0)
		res = -1;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (res);
}

/*
**			funciones extra para rows & cols
**			ft_map_check_good_rc.c
*/

int			solo_hay_unos(t_data *data1, char **str, int i, int j)
{
	int		max_y;

	max_y = data1->map_max_y + 1;
	while (i < max_y && (str[i][j] == '1' || str[i][j] == ' '))
		i++;
	if (i == max_y)
		return (1);
	return (0);
}

int			no_unos(t_data *data1, char **str, int i, int j)
{
	int		max_y;

	if (str[i - 1][j] == '0')
		return (1);
	max_y = data1->map_max_y + 1;
	while (i < max_y)
	{
		if (str[i][j] == '1')
			return (-1);
		if (str[i][j] == '0')
			return (1);
		i++;
	}
	return (1);
}
/*
**	while (str[i] != 0)
**	{
**		while (str[i][j] != '\0')
**		{
**			printf("%c", str[i][j]);
**			j++;
**		}
**		printf("|\n");
**		j = 0;
**		i++;
**	}
**	i = 0;
*/
