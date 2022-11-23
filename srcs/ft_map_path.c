/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:11:58 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 11:41:39 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_ident(t_data *data1, char *raw, int i)
{
	int		ret;

	data1->c1 = raw[i];
	i++;
	while (raw[i] != '\0' && raw[i] == ' ')
		i++;
	if (raw[i] == 'O' || raw[i] == 'E' || raw[i] == 'A')
	{
		data1->c2 = raw[i];
		i++;
	}
	while (raw[i] != '\0' && raw[i] == ' ')
		i++;
	if (raw[i] != '.' && raw[i] != '/')
		return (ft_error(11));
	if ((data1->c1 == 0 || data1->c2 == 0) && data1->c1 != 'S')
		return (ft_error(12));
	ret = ft_paths(data1, raw, i);
	if (ret < 0)
		return (0);
	if (raw[ret] != '\n')
		return (ft_error(8));
	return (ret);
}

int			ft_paths(t_data *data1, char *raw, int i)
{
	int		j;
	int		k;
	char	*str;

	j = 0;
	k = 0;
	while (raw[i + j] != ' ' && raw[i + j] != '\n')
		j++;
	str = malloc(j * sizeof(char) + 1);
	if (str == NULL)
		return (ft_error(500));
	str[j] = '\0';
	while (k < j)
	{
		str[k] = raw[i + k];
		k++;
	}
	if (ft_pass_path(data1, str) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	data1->i_letters++;
	return (i + j);
}

int			ft_pass_path(t_data *data1, char *str)
{
	if (data1->c1 == 'N' && data1->c2 == 'O')
		return (ft_prepare_images(data1, str, 0));
	if (data1->c1 == 'S' && data1->c2 == 'O')
		return (ft_prepare_images(data1, str, 2));
	if (data1->c1 == 'W' && data1->c2 == 'E')
		return (ft_prepare_images(data1, str, 1));
	if (data1->c1 == 'E' && data1->c2 == 'A')
		return (ft_prepare_images(data1, str, 3));
	if (data1->c1 == 'S')
		return (ft_prepare_images(data1, str, 4));
	return (-1);
}
