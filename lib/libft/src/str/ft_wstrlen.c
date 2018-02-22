/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:23:21 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:19:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	ft_sizechar(wchar_t c)
{
	if (!(c >> 7))
		return (1);
	if (!(c >> 11))
		return (2);
	if (!(c >> 16))
		return (3);
	return (4);
}

size_t		ft_wstrlen(wchar_t *str)
{
	size_t		size;

	size = 0;
	while (*str)
	{
		size += ft_sizechar(*str);
		str++;
	}
	return (size);
}
