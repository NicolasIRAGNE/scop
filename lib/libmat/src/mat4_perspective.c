/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_perspective.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:27:31 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 17:03:29 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	mat4_perspective(float angle, float ratio, float near, float far)
{
	t_mat4	ret;
	float	t;

	(void)angle;
	(void)ratio;
	(void)near;
	(void)far;
	t = tanf(angle / 2.f);
	ret = mat4_new();
	ret[0] = 1.f / (t * ratio);
	ret[5] = 1.f / t;
	ret[10] = (-near - far) / (far - near);
	ret[11] = -1.f;
	ret[14] = -2.f * far * near / (far - near);
	ret[15] = 0.f;
	return (ret);
}
