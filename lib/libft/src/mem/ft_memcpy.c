/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:18:41 by iburel            #+#    #+#             */
/*   Updated: 2018/02/10 16:02:42 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "type.h"

void	ft_memcpy(void *dest, void *src, int len)
{
	while (len >= 8)
	{
		*((t_uint64 *)dest) = *((t_uint64 *)src);
		dest = (void *)((t_uint64 *)dest + 1);
		src = (void *)((t_uint64 *)src + 1);
		len -= 8;
	}
	while (len > 0)
	{
		*((t_uint8 *)dest) = *((t_uint8 *)src);
		dest = (void *)((t_uint8 *)dest + 1);
		src = (void *)((t_uint8 *)src + 1);
		len -= 1;
	}
}
