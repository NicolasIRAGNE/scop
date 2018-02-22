/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:19:15 by iburel            #+#    #+#             */
/*   Updated: 2018/02/10 16:02:19 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "type.h"

void	ft_memset(void *data, int octet, size_t len)
{
	t_int64		octet64;

	octet64 = octet | (octet << 8);
	octet64 |= (octet64 << 16);
	octet64 |= (octet64 << 32);
	while (len >= 8)
	{
		*((t_uint64 *)data) = octet64;
		data = (void *)((t_uint64 *)data + 1);
		len -= 8;
	}
	while (len > 0)
	{
		*((t_uint8 *)data) = octet;
		data = (void *)((t_uint8 *)data + 1);
		len -= 1;
	}
}
