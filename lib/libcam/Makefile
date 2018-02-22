# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:12:46 by niragne           #+#    #+#              #
#    Updated: 2018/02/19 14:13:36 by niragne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcam.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = cam_orient.c cam_move.c cam_lookat.c cam_settarget.c

SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ_PATH = obj
INCLUDES_PATH = include
INCLUDES = -I $(INCLUDES_PATH)
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

obj/%.o: $(SRC_PATH)/%.c include/libcam.h include/libft.h include/libmat.h
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re : clean all