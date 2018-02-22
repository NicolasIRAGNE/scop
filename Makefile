# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 17:55:23 by niragne           #+#    #+#              #
#    Updated: 2018/02/22 15:33:16 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCL_DIR	= include
INCL		= $(INCL_DIR)/ft_scop.h

SDL_DIR = ~/.brew/Cellar/sdl2/2.0.7

SDL_IMAGE_DIR = ~/.brew/Cellar/sdl2_image/2.0.2

SDL_LIB = $(SDL_DIR)/lib

SDL_IMAGE_LIB = $(SDL_IMAGE_DIR)/lib

SDL_INCL = $(SDL_DIR)/include
SDL_IMAGE_INCL = $(SDL_IMAGE_DIR)/include -I $(SDL_INCL)/SDL2

LIB_PATH = lib

LIBFT_DIR				=	$(LIB_PATH)/libft
LIBFT					=	$(LIBFT_DIR)/libft.a
LIBFT_INCL				=	$(LIBFT_DIR)/include

LIBMAT_DIR				=	$(LIB_PATH)/libmat
LIBMAT					=	$(LIBMAT_DIR)/libmat.a
LIBMAT_INCL				=	$(LIBMAT_DIR)/include

LIBCAM_DIR 				=	$(LIB_PATH)/libcam
LIBCAM					=	$(LIBCAM_DIR)/libcam.a
LIBCAM_INCL				=	$(LIBCAM_DIR)/include

SRCS = init_sdl.c init_buffer.c create_prog.c shader_build.c main.c

SRC = $(addprefix src/, $(SRCS))

OBJ = $(addprefix obj/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBMAT) $(LIBFT) $(LIBCAM) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -L $(SDL_LIB) -L $(SDL_IMAGE_LIB) $(LIBMAT) $(LIBFT) $(LIBCAM) -lsdl2 -framework opengl -framework opencl -lsdl2_image

obj/%.o: src/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I include -I $(SDL_INCL) -I $(LIBFT_INCL) -I $(LIBMAT_INCL) -I $(LIBCAM_INCL) -I $(SDL_IMAGE_INCL)

$(LIBFT):
	make -j -C $(LIBFT_DIR)

$(LIBMAT):
	make -j -C $(LIBMAT_DIR)

$(LIBCAM):
	make -j -C $(LIBCAM_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMAT_DIR) clean
	make -C $(LIBCAM_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(LIBMAT)
	rm -f $(LIBCAM)

re: fclean
	make -j

.PHONY: all $(LIBFT) $(LIBMAT) $(LIBCAM) clean fclean re
