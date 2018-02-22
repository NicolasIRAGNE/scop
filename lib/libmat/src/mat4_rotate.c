/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:14:36 by niragne           #+#    #+#             */
/*   Updated: 2018/02/16 15:15:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <math.h>

static t_mat4   get_rot(t_vec3 v, float angle)
{
    t_mat4  ret;
    float   c;
    float   s;

    s = sin(angle);
    c = cos(angle);
    ret = mat4_new();
    ret[0] = v.x * v.x * (1.0 - c) + c;
    ret[1] = v.x * v.y * (1.0 - c) + v.z * s;
    ret[2] = v.x * v.z * (1.0 - c) - v.y * s;
    ret[3] = 0;
    ret[4] = v.x * v.y * (1.0 - c) - v.z * s;
    ret[5] = v.y * v.y * (1.0 - c) + c;
    ret[6] = v.y * v.z * (1.0 - c) + v.x * s;
    ret[7] = 0;
    ret[8] = v.x * v.z * (1.0 - c) + v.y * s;
    ret[9] = v.y * v.z * (1.0 - c) - v.x * s;
    ret[10] = v.z * v.z * (1.0 - c) + c;
    ret[11] = 0;
    ret[12] = 0;
    ret[13] = 0;
    ret[14] = 0;
    ret[15] = 1;
    return (ret);
}

/*static t_mat4   get_rot(t_vec3 *v, float angle)
{
    t_mat4  ret;
    float   c;
    float   s;

    c = cos(angle);
    s = sin(angle);
    ret = mat4_new();
	ret[0] = v->x * v->x * (1.0 - c) + c;
	ret[1] = v->x * v->y * (1.0 - c) + v->z * s;
	ret[2] = v->x * v->z * (1.0 - c) - v->y * s;
	ret[4] = v->y * v->x * (1.0 - c) - v->z * s;
	ret[5] = v->y * v->y * (1.0 - c) + c;
	ret[6] = v->y * v->z * (1.0 - c) + v->x * s;
	ret[8] = v->z * v->x * (1.0 - c) + v->y * s;
	ret[9] = v->z * v->y * (1.0 - c) - v->x * s;
	ret[10] = v->z * v->z * (1.0 - c) + c;
	ret[15] = 1.0;
    return (ret);
}
*/

void    mat4_rotate(t_mat4 *mat, t_vec3 v, float angle)
{
    t_mat4 mat_rot;
    t_mat4 tmp;

    mat_rot = get_rot(v, angle);
    tmp = *mat;
    *mat = mat4_mult(*mat, mat_rot);
    free(tmp);
}
