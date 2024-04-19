# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 23:02:48 by nkannan           #+#    #+#              #
#    Updated: 2024/04/19 23:05:40 by nkannan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# コンパイラの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

# ディレクトリとファイルの設定
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes
SRCS = fractal.c main.c utils.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = fractol

# プログラムのビルドに必要なルール
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

# オブジェクトファイルの生成ルール
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# 不要なファイルの削除ルール
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# 再ビルドルール
re: fclean all

# 特殊ターゲット
.PHONY: all clean fclean re
