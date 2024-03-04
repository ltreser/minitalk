# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 05:57:35 by ltreser           #+#    #+#              #
#    Updated: 2024/03/04 03:00:01 by ltreser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

SRC1 = server.c

SRC2 = client.c

SRC_DIR = src/

OBJ1 = $(addprefix $(SRC_DIR), $(SRC1:.c=.o))

OBJ2 = $(addprefix $(SRC_DIR), $(SRC2:.c=.o))

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3

LDLIBS = -lft

LDFLAGS = -L libft

RM = rm -rf

LIBFT = libft/libft.a

all: $(NAME1) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c  $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME1): $(LIBFT) $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LDFLAGS) $(LDLIBS)

$(NAME2): $(LIBFT) $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: re fclean clean all
