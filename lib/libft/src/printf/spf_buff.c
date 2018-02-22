/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:45:17 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:30:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char	*g_buf;
static int	g_i;

void	spf_init_buff(char *str)
{
	g_i = 0;
	g_buf = str;
}

void	spf_buff(char *str, int len)
{
	ft_memcpy(g_buf + g_i, str, len);
	g_i += len;
}
