# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    conv.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:11:39 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 17:35:42 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_CONV		=	$(INCL_PATH)/conv.h

SRCS_CONV		=	ft_atoi.c ft_atoi_split.c ft_itoa.c ft_tolower.c ft_toupper.c
SRC_CONV		=	$(addprefix $(SRC_CONV_PATH)/, $(SRCS_CONV))
OBJS_CONV		=	$(SRCS_CONV:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_CONV_PATH)/%.c $(INCL_CONV)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)