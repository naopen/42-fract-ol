# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 23:02:48 by nkannan           #+#    #+#              #
#    Updated: 2024/04/22 01:16:24 by nkannan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
SANITIZE = -fsanitize=address -g

LIBFT = libft/libft.a
LIBFT_DIR = libft

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes
SRCS = fractol.c main.c utils.c hooks.c color.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = fractol

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

leak: $(LIBFT)
	$(CC) $(SRCS:%=$(SRC_DIR)/%) $(LIBFT) $(CFLAGS) $(SANITIZE) -I$(INC_DIR) -I$(LIBFT_DIR) $(MLXFLAGS) -o $(NAME)
	./$(NAME) julia 0 0.67

.PHONY: all clean fclean re leak
