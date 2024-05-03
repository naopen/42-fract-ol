# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 23:02:48 by nkannan           #+#    #+#              #
#    Updated: 2024/05/03 20:47:56 by nkannan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SANITIZE = -fsanitize=address -g

LIBFT = libft/libft.a
LIBFT_DIR = libft

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes
SRCS = fractol.c main.c utils.c hooks.c color.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = fractol

.PHONY: all clean fclean re leak

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

leak: $(LIBFT) $(MLX)
	$(CC) $(SRCS:%=$(SRC_DIR)/%) $(LIBFT) $(CFLAGS) $(SANITIZE) -I$(INC_DIR) -I$(LIBFT_DIR) $(MLXFLAGS) -o $(NAME)
	./$(NAME) julia 0 0.67
