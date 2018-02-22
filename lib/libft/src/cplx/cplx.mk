# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cplx.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:49 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 17:35:46 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_CPLX		=	$(INCL_PATH)/cplx.h

SRCS_CPLX		=	ft_cplxadd.c ft_cplxdiv.c ft_cplxmod.c ft_cplxmult.c \
					ft_cplxnew.c ft_cplxsqrt.c ft_cplxsub.c
SRC_CPLX		=	$(addprefix $(SRC_CPLX_PATH)/, $(SRCS_CPLX))
OBJS_CPLX		= 	$(SRCS_CPLX:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_CPLX_PATH)/%.c $(INCL_CPLX)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)