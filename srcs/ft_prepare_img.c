/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:57:27 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 11:42:52 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**			GET RESOLUTION FOR PICS
*/

int			error_check_img(t_data *data1, int ori)
{
	if (ori == 0 && data1->entered_no == 1)
		return (ft_error(13));
	else if (ori == 0)
		data1->entered_no = 1;
	if (ori == 1 && data1->entered_we == 1)
		return (ft_error(13));
	else if (ori == 1)
		data1->entered_we = 1;
	if (ori == 2 && data1->entered_so == 1)
		return (ft_error(13));
	else if (ori == 2)
		data1->entered_so = 1;
	if (ori == 3 && data1->entered_ea == 1)
		return (ft_error(13));
	else if (ori == 3)
		data1->entered_ea = 1;
	if (ori == 4 && data1->entered_s == 1)
		return (ft_error(13));
	else if (ori == 4)
		data1->entered_s = 1;
	return (1);
}

int			ft_prepare_images(t_data *data1, char *str, int ori)
{
	if (error_check_img(data1, ori) < 0)
		return (-1);
	data1->relative_path[ori] = str;
	data1->img_t[ori] = mlx_xpm_file_to_image(data1->mlx,
	data1->relative_path[ori], &data1->img_width[ori], &data1->img_height[ori]);
	if (data1->img_t[ori] == NULL)
		return (ft_error(14));
	data1->img_t_addr[ori] = mlx_get_data_addr(data1->img_t[ori],
	&data1->t_bits_per_pixel[ori], &data1->t_line_length[ori],
													&data1->t_endian[ori]);
	return (1);
}
