/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:29:57 by iburel            #+#    #+#             */
/*   Updated: 2017/12/16 18:01:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_return(void *c, int ret)
{
	g_pf_buff(c, ret);
	return (ret);
}

int			pf_putchar(wchar_t c)
{
	unsigned int	octet;

	if (!(c >> 7))
		return (ft_return(&c, 1));
	if (!(c >> 11))
	{
		octet = (((c & 0x3f) << 8) | (c >> 6)) | 0x80c0;
		return (ft_return(&octet, 2));
	}
	if (!(c >> 16))
	{
		octet = (((c & 0x3f) << 16) | (((c >> 6) & 0x3f) << 8)
				| (c >> 12)) | 0x8080e0;
		return (ft_return(&octet, 3));
	}
	if (!(c >> 21))
	{
		octet = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		return (ft_return(&octet, 4));
	}
	return (-1);
}
