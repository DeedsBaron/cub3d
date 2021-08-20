# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 15:52:28 by dbaron            #+#    #+#              #
#    Updated: 2021/04/05 16:59:29 by dbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FRAMEWORKS = -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -MMD -O2

LIBFT = ./libs/libft/

LIB = ./libs/libft/libft.a

MLX = ./libs/mlx/

MLIB = ./libs/mlx/libmlx.a

DIR_GS = ./general_src

DIR_BS = ./bonus_src

DIR_MS = ./man_src

DIR_GO = ./general_obj

DIR_BO = ./bonus_obj

DIR_MO = ./mandatory_obj

CC = gcc

MAN_SOURCES = main.c

BONUS_SOURCES = draw_bonus.c main_bonus.c music_bonus.c

GEN_SOURCES = check_parsed.c draw.c free.c get_next_line.c \
		get_next_line_utils.c init.c init2.c \
		movement.c parse_args.c parse_map.c raycast.c \
		rotation.c screenshot.c sprites.c start_pos.c \
		textures.c utils.c utils2.c validation.c

GEN_SRCS = $(addprefix $(DIR_GS)/,${GEN_SOURCES})

B_SRCS = $(addprefix $(DIR_SB)/,${BONUS_SOURCES})

M_SRC = $(addprefix $(DIR_MS)/,${MAN_SOURCES})

G_OBJS = $(addprefix $(DIR_GO)/,${GEN_SOURCES:.c=.o})

B_OBJS = $(addprefix $(DIR_BO)/,${BONUS_SOURCES:.c=.o})

M_OBJS = $(addprefix $(DIR_MO)/,${MAN_SOURCES:.c=.o})

all: dir lib $(NAME)

dir: 
	@echo "\033[0;32m"
	mkdir -p general_obj
	mkdir -p bonus_obj
	mkdir -p mandatory_obj

lib:
	@echo "\033[0;32m"
	make -C $(LIBFT)
	@echo "\033[0;34m"
	make -C $(MLX)
	@echo "\033[0;36m"

$(DIR_GO)/%.o: $(DIR_GS)/%.c
	$(CC) $(FLAGS) -c $< -o $@ -g

$(DIR_MO)/%.o: $(DIR_MS)/%.c
	$(CC) $(FLAGS) -c $< -o $@ -g

$(DIR_BO)/%.o: $(DIR_BS)/%.c
	$(CC) $(FLAGS) -c $< -o $@ -g

$(NAME): $(M_OBJS) $(G_OBJS)
	@echo "\033[0;35m"
	$(CC) $(FLAGS) $^ -o $@ $(LIB) $(MLIB) $(FRAMEWORKS) -g
	chmod 777 $(NAME)
bonus: $(B_OBJS) $(G_OBJS)
	@echo "\033[0;35m"
	$(CC) $(FLAGS) $^ -o $(NAME) $(LIB) $(MLIB) $(FRAMEWORKS) -g
	chmod 777 $(NAME)
norm:
	@echo "\033[0;32mnorminette $(DIR_GS)/*.c\033[0m"
	@norminette $(DIR_GS)/*.c
	@echo "\033[0;32mnorminette $(DIR_BS)/*.c\033[0m"
	@norminette $(DIR_BS)/*.c
	@echo "\033[0;32mnorminette $(DIR_MS)/*.c\033[0m"
	@norminette $(DIR_MS)/*.c
	@echo "\033[0;32mnorminette includes/*.h\033[0m"
	@norminette includes/*.h
	@echo "\033[0;32mnorminette $(LIBFT)/*.c\033[0m"
	@norminette $(LIBFT)/*.{c,h}
clean:
	@echo "\033[0;33m"
	rm -rf $(DIR_BO)
	rm -rf $(DIR_GO)
	rm -rf $(DIR_MO)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean: clean
	@echo "\033[0;33m"
	rm -f $(NAME)
	rm -f $(MLIB)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all lib clean fclean re

-include $(OBJS:.o=.d)
-include $(B_OBJS:.o=.d)