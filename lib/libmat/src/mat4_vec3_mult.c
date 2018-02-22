/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vec3_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:14:48 by niragne           #+#    #+#             */
/*   Updated: 2018/02/16 15:58:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	mat4_vec3_mult(t_mat4 m, t_vec3 v)
{
	t_mat4	ret;

    ret = mat4_id_new();
	ret[0] = v.x;
	ret[5] = v.y;
	ret[10] = v.z;
    ret = mat4_mult(ret, m);
	return (ret);
}
