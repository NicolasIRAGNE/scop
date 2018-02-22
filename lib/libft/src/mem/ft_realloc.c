/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:11:48 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:09:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "put.h"
#include <stdlib.h>

void	*ft_realloc(void *data, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		ft_afferror("error malloc in ft_realloc");
	if (!data)
		return (tmp);
	ft_memmove(tmp, data, size);
	free(data);
	return (tmp);
}
