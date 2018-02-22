/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:23:37 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:28:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	i;
	size_t	len;

	dst_cpy = dst;
	src_cpy = (char *)src;
	i = size;
	while (i-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	len = dst_cpy - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (i != 1)
		{
			*dst_cpy++ = *src_cpy;
			i--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (len + (src_cpy - src));
}
