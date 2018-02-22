/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 10:41:34 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:24:04 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "type.h"

static char	*ft_strlen_bytes(char *cp)
{
	if (!cp[0])
		return (cp);
	if (!cp[1])
		return (cp + 1);
	if (!cp[2])
		return (cp + 2);
	if (!cp[3])
		return (cp + 3);
	if (!cp[4])
		return (cp + 4);
	if (!cp[5])
		return (cp + 5);
	if (!cp[6])
		return (cp + 6);
	if (!cp[7])
		return (cp + 7);
	return (NULL);
}

size_t		ft_strlen(const char *str)
{
	t_uint64	*lw_ptr;
	t_uint64	lw;
	char		*tmp;

	lw_ptr = (t_uint64 *)str;
	while (1)
	{
		lw = *lw_ptr;
		if ((lw - 0x0101010101010101L) & 0x8080808080808080L)
		{
			if ((tmp = ft_strlen_bytes((char *)lw_ptr)))
				return (tmp - str);
		}
		lw_ptr++;
	}
}
