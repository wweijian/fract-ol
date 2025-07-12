# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 06:33:12 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/13 17:56:58 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HDRS = ./includes/

MLX_PATH = mlx/
MLX = ${MLX_PATH}libmlx.a

LIBFT_PATH = libft/
LIBFT = ${LIBFT_PATH}libft.a

# COMPILE RULES
CC = cc
CFLAGS = -Werror -Wextra -Wall

SRCS_PATH = ./srcs/
SRCS = main.c draw.c exit.c init.c validate_argument.c fractals.c \
		utils.c events_bonus.c newton_bonus.c
SRCS := ${addprefix ${SRCS_PATH}, ${SRCS}}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I${HDRS} -Imlx

${NAME}: ${SRCS} ${LIBFT} ${MLX} ${HDRS}
		${CC} ${CFLAGS} ${SRCS} -L. ${LIBFT} -I${HDRS} -Lmlx -Imlx -lmlx -lXext -lX11 -lm -o ${NAME}

${MLX}:
	@make -C mlx
	@echo ">> MLX made <<"

${LIBFT}:
	@make -C ${LIBFT_PATH}
	@echo ">> libft made <<"

mandelbrot: all
	./fractol m 0xFFCC11

m: mandelbrot

julia: all
	./fractol j 0xFFCC11 -0.745429 1.01235

j: julia

newton: all
	./fractol n 0xFFCC11

n: newton

bonus: ${NAME}

clean:
	rm -rf $(OBJ_PATH)
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all re clean fclean mandelbrot julia newton m j n