/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:50:00 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point		ft_translation(t_point p, t_vector v)
{
	t_point		new;
	int			x;
	int			y;
	int			z;

	x = p.x + v.x;
	y = p.y + v.y;
	z = p.z + v.z;
	new = ft_newpoint(x, y, z);
	return (new);
}
