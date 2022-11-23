# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 16:59:17 by ahernand          #+#    #+#              #
#    Updated: 2021/04/17 14:27:03 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@gcc -w srcs/cub3d.h						\
	libX/minilibx_mms_20200219/mlx.h			\
	libX/minilibx_mms_20200219/libmlx.dylib		\
	libx/minilibx_opengl_20191021/libmlx.a		\
	srcs/main.c									\
	srcs/hooks.c								\
	srcs/ft_error.c								\
	srcs/ft_read.c								\
	srcs/ft_map_collect_lines.c					\
	srcs/ft_map_check_good.c					\
	srcs/ft_map_check_good_rc.c					\
	srcs/ft_map_path.c							\
	srcs/ft_map_res.c							\
	srcs/ft_map_cf.c							\
	srcs/ft_map_info.c							\
	srcs/ft_prepare_img.c						\
	srcs/ft_img_handle.c						\
	srcs/ft_print_map.c							\
	srcs/ft_player.c							\
	srcs/ft_player_ray.c						\
	srcs/ft_player_pixel.c						\
	srcs/ft_ray.c								\
	srcs/ft_ray_h.c								\
	srcs/ft_ray_v.c								\
	srcs/ft_sprite.c							\
	srcs/ft_sprite_2.c							\
	srcs/ft_strlen.c							\
	srcs/ft_putchar_fd.c						\
	srcs/ft_putstr_fd.c							\
	srcs/ft_save_bmp.c							\
	srcs/ft_split.c								\
	-Wall -Wextra -Werror -Lmlx -L. -lmlx		\
	-framework OpenGL -framework AppKit
	@cd srcs && rm cub3d.h.gch
	@mv a.out libX/minilibx_mms_20200219/cub3D

bonus: all

start:
	@cd libX/minilibx_opengl_20191021 && (MAKE -Wno-deprecated-declarations)
	@cd libX/minilibx_mms_20200219 && (MAKE -Wno-deprecated-declarations-Wdeprecated-declarations)
	clear && echo "-> all: \033[0;32m[OK] [OK] [OK]"

clean:
	rm -f libX/minilibx_mms_20200219/a.out
	rm -f libX/minilibx_mms_20200219/cub3D

fclean:
	@cd libX/minilibx_opengl_20191021 && make clean
	@cd libX/minilibx_mms_20200219	&& make clean

re: fclean clean

.PHONY:		all clean fclean re
