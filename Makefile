# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 17:05:23 by vpushkar          #+#    #+#              #
#    Updated: 2025/05/22 16:11:08 by vpushkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# ==== Directories ====
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# ==== Libft ====
LIBFT_DIR = libft_extended
LIBFT_REPO = https://github.com/Vspaceman11/libft_extended.git
LIBFT_A = $(LIBFT_DIR)/libft_extended.a

# ==== MLX42 ====
MLX_DIR = MLX42
MLX_REPO = https://github.com/codam-coding-college/MLX42.git
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -I$(MLX_DIR)/include -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

# ==== Source and Object Files ====
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

RM = rm -f
MKDIR = mkdir -p

# ==== Colored Messages ====
YELLOW = \033[1;33m
GREEN  = \033[1;32m
RED    = \033[1;31m
BLUE   = \033[1;34m
RESET  = \033[0m

# ==== Targets ====
all: $(LIBFT_A) $(MLX_LIB) $(NAME)
	@echo "$(GREEN)✓ Build complete: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)→ Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/inc -I$(MLX_DIR)/include -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)→ Linking $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft_extended $(MLX_FLAGS) -o $@

# ==== Libft ====
$(LIBFT_A):
	@echo "$(BLUE)→ Checking libft...$(RESET)"
	@test -d $(LIBFT_DIR) || git clone --depth=1 $(LIBFT_REPO) $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN)✓ libft ready$(RESET)"

# ==== MLX42 ====
$(MLX_LIB):
	@echo "$(BLUE)→ Checking MLX42...$(RESET)"
	@test -d $(MLX_DIR) || git clone --depth=1 $(MLX_REPO) $(MLX_DIR)
	@cmake -B $(MLX_DIR)/build $(MLX_DIR) > /dev/null
	@cmake --build $(MLX_DIR)/build > /dev/null
	@echo "$(GREEN)✓ MLX42 ready$(RESET)"

# ==== Cleanup ====
clean:
	@echo "$(RED)✗ Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null || true

fclean: clean
	@echo "$(RED)✗ Removing binary: $(NAME)$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null || true
	@if [ "$(REMOVE_LIBFT)" = "1" ]; then rm -rf $(LIBFT_DIR); fi
	@if [ "$(REMOVE_MLX)" = "1" ]; then rm -rf $(MLX_DIR); fi

re: fclean all

.PHONY: all clean fclean re
