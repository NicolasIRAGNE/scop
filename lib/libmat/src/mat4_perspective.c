/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_perspective.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:27:31 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 14:34:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	mat4_perspective(float angle, float ratio, float near, float far)
{
	t_mat4	ret;
	float	t;
	(void)near;
	(void)far;
	(void)angle;

	t = 1.f;
	ret = mat4_new();
	ret[0] = ratio / t;
	ret[5] = 1.f / t;
	ret[10] = 0.1f;
//	ret[10] = -far / (far - near);
//	ret[11] = -1;
//	ret[14] = -far * near / (far - near);
	ret[15] = 1.f;
	return (ret);
}
