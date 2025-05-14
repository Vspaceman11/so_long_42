# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 17:05:23 by vpushkar          #+#    #+#              #
#    Updated: 2025/05/14 17:05:26 by vpushkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# ==== LIBFT ====
LIBFT_DIR = libft_extended
LIBFT_REPO = https://github.com/Vspaceman11/libft_extended.git
LIBFT_A = $(LIBFT_DIR)/libft_extended.a

# ==== MLX42 ====
MLX_DIR = MLX42
MLX_REPO = https://github.com/codam-coding-college/MLX42.git
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -I$(MLX_DIR)/include -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

# ==== SOURCES ====
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(LIBFT_A) $(MLX_LIB) $(NAME)

# ==== LIBFT ====
$(LIBFT_A):
	test -d $(LIBFT_DIR) || git clone --depth=1 $(LIBFT_REPO) $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

# ==== MLX42 ====
$(MLX_LIB):
	test -d $(MLX_DIR) || git clone --depth=1 $(MLX_REPO) $(MLX_DIR)
	cmake -B $(MLX_DIR)/build $(MLX_DIR)
	cmake --build $(MLX_DIR)/build

# ==== BUILD ====
%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR)/inc -I$(MLX_DIR)/include -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft_extended $(MLX_FLAGS) -o $@

# ==== CLEANUP ====
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true
	@if [ "$(REMOVE_LIBFT)" = "1" ]; then \
		echo "Removing libft_extended directory."; \
		rm -rf $(LIBFT_DIR); \
	else \
		echo "Keeping libft_extended directory."; \
	fi
	@if [ "$(REMOVE_MLX)" = "1" ]; then \
		echo "Removing MLX42 directory."; \
		rm -rf $(MLX_DIR); \
	else \
		echo "Keeping MLX42 directory."; \
	fi

re: fclean all

.PHONY: all clean fclean re
