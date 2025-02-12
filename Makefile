# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:08:21 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/02/12 21:54:14 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I library/libft
CFLAGS += -I inc

LIBFT = library/libft/libft.a

SRCS = src/main.c\
	src/check_map.c\
	src/allocate_mem.c\

OBJ = $(SRCS:%.c=objs/%.o)
	
all: $(LIBFT) $(NAME)

$(NAME): objs $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)so_long ready$(WHITE)"

objs:
	@mkdir -p objs/src/

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf objs
	@rm -rf bns_objs
	@echo "Objetcs files deleted."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNS_NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re