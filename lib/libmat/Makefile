# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 14:43:13 by niragne           #+#    #+#              #
#    Updated: 2018/02/19 17:55:04 by niragne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmat.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = mat4_new.c mat3_new.c mat3_mult.c mat4_mult.c mat3_id_new.c \
			mat4_id_new.c mat4_rotate.c vec3_normalize.c mat4_vec3_mult.c \
			mat4_translate.c vec3_cross.c vec3_add.c vec3_sub.c mat4_perspective.c \
			vec3_dot.c

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

obj/%.o: $(SRC_PATH)/%.c include/libmat.h include/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re : clean all