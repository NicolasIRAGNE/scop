/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:17:51 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 23:08:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>

void	*ft_memalloc(size_t n)
{
	void	*tmp;

	if (!(tmp = malloc(n)))
		return (NULL);
	ft_bzero(tmp, n);
	return (tmp);
}
