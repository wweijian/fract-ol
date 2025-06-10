# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 06:33:12 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/10 18:45:16 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HDRS = ./includes/
LIB_PATH = ./libraries/

#MLX_OS = linux
MLX_OS = mac_os/
MLX_PATH = ${LIB_PATH}mlx/${MLX_OS}
MLX = ${MLX_PATH}libmlx.a

LIBFT_PATH = ${LIB_PATH}libft/
LIBFT = ${LIBFT_PATH}libft.a

# COMPILE RULES
CC = cc
CFLAGS = -Werror -Wextra -Wall

SRCS_PATH = ./srcs/
SRCS = main.c arg_parse.c init.c
SRCS := ${addprefix ${SRCS_PATH}, ${SRCS}}

# OBJS_PATH = ./objs/
# OBJS = ${SRCS:.c=.o}
# OBJS := ${addprefix ${OBJS_PATH}, ${OBJS}}

all:
	cc srcs/*.c -L. -lmlx -framework OpenGL -framework AppKit -o fractol -I includes/ -L. libraries/libft/libft.a -g -O0

# all:
# 	cc srcs/*.c -L. libraries/libft/libft.a -I includes -lmlx -lXext -lX11 -lm -g -O0 -o fractol

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${HDRS}

${NAME}: ${LIBFT} ${MLX} ${HDRS} #woudl this work without the flags at the end?
#	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX} -I ${HDRS} -lXext -lX11 -lm
	${CC} ${CFLAGS} ${SRCS} -L. ${LIBFT} ${MLX} -I ${HDRS} -o ${NAME}

mandelbrot: all
	./fractol m 0xFFCC11

m: mandelbrot

julia: all
	./fractol j 0xFFCC11 -0.745429 0.05

j: julia

newton: all
	./fractol n 0xFFCC11

n: all
	./fractol n 0xFFCC11

memcheck:
	cc -fsanitize=address -g -O0 srcs/*.c -L. -lmlx -framework OpenGL -framework AppKit -o fractol -I includes/ -L. libraries/libft/libft.a
	./fractol m 0xFAC011

${MLX}:
	make -sC ${MLX_PATH}
	@echo "MLX made"

${LIBFT}:
	make -C ${LIBFT_PATH}

bonus: all

clean:
	rm -rf $(OBJ_PATH)
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean