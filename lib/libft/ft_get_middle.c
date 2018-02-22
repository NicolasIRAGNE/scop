/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_middle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:50:04 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_point		ft_get_middle(t_point a, t_point b)
{
	t_point middle;
	int		x;
	int		y;
	int		z;

	x = (a.x + b.x) / 2;
	y = (a.y + b.y) / 2;
	z = (a.z + b.z) / 2;
	middle = ft_newpoint(x, y, z);
	return (middle);
}
