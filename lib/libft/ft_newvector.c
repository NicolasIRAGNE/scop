/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newvector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/04 13:23:18 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_vector		*ft_newvector(int x, int y, int z)
{
	t_vector *vector;

	if (!(vector = malloc(sizeof(t_vector))))
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}
