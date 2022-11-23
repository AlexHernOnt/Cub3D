/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:20:11 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 19:13:38 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				fill_bmp(t_data *data1, char **str)
{
	int				i;
	int				j;
	int				x;
	int				y;

	i = HEADER_SIZE;
	y = data1->wys;
	while (y--)
	{
		x = -1;
		while (++x < data1->wxs)
		{
			j = (x * (data1->bits_per_pixel / 8))
				+ (y * data1->line_length);
			*(*str + i++) = *(data1->addr + j++);
			*(*str + i++) = *(data1->addr + j++);
			*(*str + i++) = *(data1->addr + j);
		}
	}
}

void				ft_header_bmp(char **str, t_data *data1)
{
	unsigned int	size;

	size = data1->wys * data1->wxs * 3;
	*(unsigned short *)*str = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*str + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(*str + 6) = 0u;
	*(unsigned char *)(*str + 10) = HEADER_SIZE;
	*(unsigned int *)(*str + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*str + 18) = data1->wxs;
	*(unsigned int *)(*str + 22) = data1->wys;
	*(unsigned short *)(*str + 26) = 1;
	*(unsigned short *)(*str + 28) = 24;
	*(unsigned int *)(*str + 30) = 0;
	*(unsigned int *)(*str + 34) = (unsigned int)size;
	*(unsigned int *)(*str + 38) = 3780;
	*(unsigned int *)(*str + 42) = 3780;
	*(int *)(*str + 46) = 0;
	*(int *)(*str + 50) = 0;
}

int					ft_save_bmp(t_data *data1)
{
	int				fd;
	unsigned int	size;
	unsigned int	i;
	char			*str;

	size = data1->wys * data1->wxs * 3;
	if (!(str = malloc((size + HEADER_SIZE))))
		ft_error(500);
	i = 0;
	while (i < size + HEADER_SIZE)
		str[i++] = 0;
	ft_header_bmp(&str, data1);
	fill_bmp(data1, &str);
	if ((fd = open("../../screenshot.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644))
	<= 0)
	{
		free(str);
		return (ft_error(3));
	}
	write(fd, str, (size + HEADER_SIZE));
	close(fd);
	free(str);
	exit(0);
	return (1);
}
