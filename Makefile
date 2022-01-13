# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 02:05:40 by gusalves          #+#    #+#              #
#    Updated: 2022/01/12 15:19:09 by gusalves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
RM	= rm -f

INCLUDES_DIR	= ./includes ./libs/libft
SRC_DIR	= ./src
OBJ_DIR	 = ./build

LIBFT_PATH	 = ./libs/libft
LIBFT	= $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
INCLUDES	= $(addprefix -I,$(INCLUDES_DIR))

SRCS	 = pipex.c pipex_utils.c child.c parent.c cmd_exec.c find_path.c 					init_var.c cmd_check.c cmd_treat.c space_treat.c errors.c
OBJS	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS	:= $(addprefix $(SRC_DIR)/,$(SRCS))

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re:	fclean all

go: all
	./pipex

.PHONY:	all clean fclean re
