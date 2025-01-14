# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafa <arafa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 10:48:54 by marvin            #+#    #+#              #
#    Updated: 2024/02/20 11:20:25 by arafa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c src

NAME = so_long
CFLAGS += -Wall -Wextra -Werror -I/usr/include -Imlx_linux
LIB = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm
CC = gcc
SRC = $(wildcard src/*.c) 
OBJDIR = obj
OBJ	= $(SRC:src/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $<  -o $@

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)  $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
