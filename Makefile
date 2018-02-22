# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 17:55:23 by niragne           #+#    #+#              #
#    Updated: 2018/02/18 16:54:14 by niragne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCL_DIR	= include
INCL		= $(INCL_DIR)/ft_scop.h

SDL_DIR = /Users/niragne/.brew/Cellar/sdl2/2.0.7

SDL_IMAGE_DIR = /Users/niragne/.brew/Cellar/sdl2_image/2.0.2

SDL_LIB = $(SDL_DIR)/lib

SDL_IMAGE_LIB = $(SDL_IMAGE_DIR)/lib

SDL_INCL = $(SDL_DIR)/include
SDL_IMAGE_INCL = $(SDL_IMAGE_DIR)/include -I $(SDL_INCL)/SDL2

LIB_PATH = lib

LIBFT					=	$(LIB_PATH)/libft
LIBFT_INCL				=	$(LIB_PATH)/libft/include

LIBMAT					=	$(LIB_PATH)/libmat
LIBMAT_INCL				=	$(LIB_PATH)/libmat/include

LIBCAM 					=	$(LIB_PATH)/libcam
LIBCAM_INCL				=	$(LIB_PATH)/libcam/include

SRCS = init_sdl.c init_buffer.c create_prog.c shader_build.c main.c

SRC = $(addprefix src/, $(SRCS))

OBJ = $(addprefix obj/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -L $(SDL_LIB) -L $(SDL_IMAGE_LIB) $(LIBFT)/libft.a $(LIBMAT)/libmat.a $(LIBCAM)/libcam.a -lsdl2 -framework opengl -framework opencl -lsdl2_image

obj/%.o: src/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I include -I $(SDL_INCL) -I $(LIBFT_INCL) -I $(LIBMAT_INCL) -I $(LIBCAM_INCL) -I $(SDL_IMAGE_INCL)

$(LIBFT):
	make -j -C $(LIBFT)

$(LIBMAT):
	make -j -C $(LIBMAT)

$(LIBCAM):
	make -j -C $(LIBCAM)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean
	make -C $(LIBMAT) clean
	make -C $(LIBCAM) clean

fclean: clean
	/bin/rm -f $(NAME)

libs:
	make -C $(LIBFT) re
	make -C $(LIBMAT) re
	make -C $(LIBCAM) re

re: fclean all
	