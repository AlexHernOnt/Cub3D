/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:42:02 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 14:47:28 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_read(t_data *data1, char *argv[], int n_read)
{
	int		fd;
	char	*raw;
	int		buff_size;

	buff_size = 500000;
	raw = malloc(sizeof(char) * buff_size);
	if (ft_strn_cub(argv[1]) < 0)
	{
		free(raw);
		return (ft_error(2));
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(raw);
		return (ft_error(3));
	}
	n_read = read(fd, raw, buff_size);
	if (n_read < 0)
	{
		free(raw);
		return (ft_error(4));
	}
	close(fd);
	return (ft_organize_map(data1, raw, n_read));
}

int			ft_organize_map(t_data *data1, char *raw, int n_read)
{
	int		i;

	i = 0;
	raw[n_read] = '\0';
	if (ft_map_collect_lines(data1, raw, i) < 0)
	{
		free(raw);
		return (-1);
	}
	free(raw);
	ft_clear_map(data1);
	ft_find_n_sprites(data1);
	if (ft_find_player_start(data1, i) < 0)
		return (-1);
	return (1);
}

int			ft_strn_cub(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) - 4;
	if (len < 0)
		return (-1);
	if (str[len] == '.')
		i++;
	if (str[len + i] == 'c')
		i++;
	if (str[len + i] == 'u')
		i++;
	if (str[len + i] == 'b')
		i++;
	if (i == 4)
		return (1);
	else
		return (-1);
}

void		ft_clear_map(t_data *data1)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (data1->map[j] != '\0')
	{
		while (data1->map[j][k] != '\0')
		{
			if (data1->map[j][k] == ' ')
				data1->map[j][k] = '1';
			k++;
		}
		k = 0;
		j++;
	}
}

void		ft_find_max_y(t_data *data1)
{
	int		i;

	i = 0;
	while (data1->map[i] != '\0')
		i++;
	data1->map_max_y = i;
}

/*
**	for (int j = 0; data1.map[j] != '\0';++j)
**	{
**		for (int k = 0; data1.map[j][k]; ++k)
**		{
**			printf("%c", data1.map[j][k]);
**			fflush(0);
**		}
**		printf("\n");
**	}
**
**
**	Use this to read 2Darray
**
**	for (int j = 0; arr_map[j] != '\0';++j)
**	{
**		for (int k = 0; arr_map[j][k]; ++k)
**		{
**			printf(" %c ", arr_map[j][k]);
**			fflush(0);
**
**}
**		printf("\n");
**	}
**
**		RIP Aborted split
**
**		This is sleepy me typing to do  split again,
**		not realizing he had alredy done it
**
**
**	int		ft_count_lines(char *str)
**	{
**		int		n_lines;
**		char	*ptr;
**
**		ptr = str;
**		n_lines = 0;
**		while (*ptr != '\0')
**		{
**			if (*ptr == '\n')
**				++n_lines;
**			++ptr;
**		}
**		return (n_lines);
**	}
**
**	void ft_map_cut()
**	{
**		will get the array raw, and double pointer array
**		for x and y and fill it up
**	}
**
**	char*		ft_each_line(char *raw)
**	{
**		char	*nl;
**		int		len;
**
**		len = 0;
**		while (raw != '\n' || raw != '\0')
**			++len;
**		if (!(nl = (char*)malloc(sizeof(char) * (len + 1))))
**			return (0);
**		arr[len] = '\0';
**		while (i < len)
**		{
**			nl[i] = raw[i];
**			++i;
**		}
**		return (nl);
**	}
**
**	void ft_read()
**	{
**		int		buff_size;
**		int		fd;
**		char*	raw;
**		char**	arr_map;
**		int		n_read;
**
**		int		size_y;
**		int		size_x;
**		int		i;
**
**		size_y = 0;
**		buff_size = 100;
**		i = 0;
**
**		raw = malloc(sizeof(char) * buff_size);
**		fd = open("map.cub", O_RDONLY);
**		n_read = read(fd, raw, buff_size);
**		raw[n_read] = '\0';
**		size_y = ft_count_lines(raw);
**
**		if (!(arr_map = (char**)malloc(sizeof(char*) * (size_y + 1))))
**			return (0);
**		arr_map[size_y + 1] = '\0';
**		while (i < size_y)
**		{
**			arr_map[i] = ft_each_line(raw);
**			++i;
**		}
**		//	ft_map_cut();
**		printf("%s__", str);
**		fflush(0);
**	}
*/
