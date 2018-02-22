# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    put.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:27:01 by iburel            #+#    #+#              #
#    Updated: 2017/12/17 20:13:30 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_PUT		=	$(INCL_PATH)/put.h

SRCS_PUT		=	ft_afferror.c
SRC_PUT			=	$(addprefix $(SRC_PUT_PATH)/, $(SRCS_PUT))
OBJS_PUT		=	$(SRCS_PUT:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_PUT_PATH)/%.c $(INCL_PUT)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)