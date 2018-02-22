/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:36:35 by niragne           #+#    #+#             */
/*   Updated: 2018/02/16 16:16:18 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void    mat4_translate(t_mat4 *mat, t_vec3 v)
{
    t_mat4 ret;
    t_mat4 tmp;

    tmp = *mat;
    ret = mat4_id_new();
    ret[12] = v.x;
    ret[13] = v.y;
    ret[14] = v.z;
    *mat = mat4_mult(*mat, ret);
    free(tmp);
}