/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:24:59 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:18:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "mem.h"
#include <stdlib.h>

char	*ft_strnew(size_t n)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(*tmp) * (n + 1))))
		return (NULL);
	ft_bzero((void *)tmp, n + 1);
	return (tmp);
}
