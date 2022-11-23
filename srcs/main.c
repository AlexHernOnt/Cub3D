/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:16 by ahernand          #+#    #+#             */
/*   Updated: 2021/04/16 19:18:44 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char *argv[])
{
	t_data	data1;

	data1.mlx = mlx_init();
	if (ft_number_of_args(&data1, argc, argv) > 0)
	{
		if (data1.save != 1)
			data1.win = mlx_new_window(data1.mlx, data1.wxs, data1.wys,
											"Alex's Cub3D");
		data1.img = mlx_new_image(data1.mlx, data1.wxs, data1.wys);
		data1.addr = mlx_get_data_addr(data1.img, &data1.bits_per_pixel,
											&data1.line_length, &data1.endian);
		data1.size_tiles = 50;
		data1.move = 0;
		if (data1.save != 1)
		{
			mlx_hook(data1.win, 2, 1L << 0, hook_press, &data1);
			mlx_hook(data1.win, 3, 1L << 0, hook_release, &data1);
			mlx_hook(data1.win, 17, 0L, hook_cross, &data1);
		}
		mlx_loop_hook(data1.mlx, ft_img_handle, &data1);
		mlx_loop(data1.mlx);
	}
	return (0);
}

int			ft_number_of_args(t_data *data1, int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc < 2 || argc > 3)
		return (ft_error(1));
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 &&
			argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's' &&
			argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e')
			data1->save = 1;
		else
			return (ft_error(20));
	}
	return (ft_read(data1, argv, i));
}
