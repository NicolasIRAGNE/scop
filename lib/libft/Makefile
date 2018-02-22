# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 22:12:15 by iburel            #+#    #+#              #
#    Updated: 2018/02/14 21:50:46 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

ifeq ($(DEBUG), yes)
	CFLAGS		+=	-g
else
	CFLAGS		+=	-Ofast
endif

OBJ_PATH		=	obj
SRC_PATH		=	src
INCL_PATH		=	include

SRC_CHAR_PATH	=	$(SRC_PATH)/char
SRC_CONV_PATH	=	$(SRC_PATH)/conv
SRC_CPLX_PATH	=	$(SRC_PATH)/cplx
SRC_FILE_PATH	=	$(SRC_PATH)/file
SRC_PRINTF_PATH	=	$(SRC_PATH)/ft_printf
SRC_LST_PATH	=	$(SRC_PATH)/lst
SRC_MEM_PATH	=	$(SRC_PATH)/mem
SRC_PUT_PATH	=	$(SRC_PATH)/put
SRC_STR_PATH	=	$(SRC_PATH)/str
SRC_PRINTF_PATH	=	$(SRC_PATH)/printf

include $(SRC_CHAR_PATH)/char.mk
include $(SRC_CONV_PATH)/conv.mk
include $(SRC_CPLX_PATH)/cplx.mk
include $(SRC_FILE_PATH)/file.mk
include $(SRC_LST_PATH)/lst.mk
include $(SRC_MEM_PATH)/mem.mk
include $(SRC_PUT_PATH)/put.mk
include $(SRC_STR_PATH)/str.mk
include $(SRC_PRINTF_PATH)/printf.mk

OBJS			=	$(OBJS_CONV) $(OBJS_CPLX) $(OBJS_FILE) $(OBJS_CHAR) $(OBJS_LST) \
					$(OBJS_MEM) $(OBJS_PUT) $(OBJS_STR) $(OBJS_PRINTF)
OBJ				=	$(addprefix $(OBJ_PATH)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
