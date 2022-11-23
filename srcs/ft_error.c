/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:19:31 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/23 14:29:30 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	if (code == 1)
		ft_putstr_fd("You didn't supply a map.\n", 2);
	if (code == 2)
		ft_putstr_fd("Not a .cub file.\n", 2);
	if (code == 3)
		ft_putstr_fd("File couldn't be open.\n", 2);
	if (code == 4)
		ft_putstr_fd("File couldn't be read.\n", 2);
	if (code == 5)
		ft_putstr_fd("Non valid characters.\n", 2);
	if (code == 6)
		ft_putstr_fd("Too few parameters.\n", 2);
	if (code == 7)
		ft_putstr_fd("Invalid characters between resoultion.\n", 2);
	if (code == 8)
		ft_putstr_fd("Invalid characters at the end of the line.\n", 2);
	if (code == 9)
		ft_putstr_fd("Invalid characters between Floor are Ceiling.\n\n", 2);
	if (code >= 10)
		ft_error_10s(code);
	if (code >= 20)
		ft_error_20s(code);
	return (1);
}

void			ft_error_10s(int code)
{
	if (code == 10)
		ft_putstr_fd("Ceiling or Floor number is over 256.\n", 2);
	if (code == 11)
		ft_putstr_fd("Invalid characters between paths.\n", 2);
	if (code == 12)
		ft_putstr_fd("Wrong identifiers.\n", 2);
	if (code == 13)
		ft_putstr_fd("Repetead identified.\n", 2);
	if (code == 14)
		ft_putstr_fd("Texture failed.\n", 2);
	if (code == 15)
		ft_putstr_fd("Two players.\n", 2);
	if (code == 16)
		ft_putstr_fd("Chars in between info and map.\n", 2);
	if (code == 17)
		ft_putstr_fd("Map is not closed correctly horizontally.\n", 2);
	if (code == 18)
		ft_putstr_fd("Map is not closed correctly vertically.\n", 2);
	if (code == 19)
		ft_putstr_fd("Map has invalid characters inside.\n", 2);
}

void			ft_error_20s(int code)
{
	if (code == 500)
		ft_putstr_fd("Malloc error\n", 2);
	if (code == 20)
		ft_putstr_fd("The second argument in not correct\n", 2);
	if (code == 21)
		ft_putstr_fd("No player\n", 2);
	if (code == 22)
		ft_putstr_fd("Incorrect Resolution\n", 2);
	if (code == 23)
		ft_putstr_fd("Characters found that aren't allowed\n", 2);
}
