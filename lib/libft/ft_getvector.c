/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:50:05 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_getvector(t_point *a, t_point *b)
{
	t_vector	*v;
	int			x;
	int			y;
	int			z;

	x = b->x - a->x;
	y = b->y - a->y;
	z = b->z - a->z;
	v = ft_newvector(x, y, z);
	if (!v)
		return (NULL);
	return (v);
}
