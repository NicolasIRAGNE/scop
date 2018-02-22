/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:47:29 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:40:21 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char	g_buf[PF_BUFF_SIZE];
static int	g_i = 0;

void	pf_buff(char *str, int len)
{
	if (g_i + len > PF_BUFF_SIZE)
	{
		write(1, g_buf, g_i);
		g_i = 0;
	}
	ft_memcpy(g_buf + g_i, str, len);
	g_i += len;
}

void	pf_putbuff(void)
{
	write(1, g_buf, g_i);
	g_i = 0;
}
