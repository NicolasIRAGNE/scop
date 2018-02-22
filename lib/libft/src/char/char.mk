# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    char.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:07:14 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 17:36:46 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_CHAR		=	$(INCL_PATH)/char.h

SRCS_CHAR		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c \
					ft_isdigit.c ft_islower.c ft_isprint.c ft_ispunct.c \
					ft_isspace.c ft_isupper.c
SRC_CHAR		=	$(addprefix $(SRC_CHAR_PATH)/, $(SRCS_CHAR))
OBJS_CHAR		=	$(SRCS_CHAR:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_CHAR_PATH)/%.c $(INCL_CHAR)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)