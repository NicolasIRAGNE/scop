/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:40:47 by niragne           #+#    #+#             */
/*   Updated: 2018/02/16 13:59:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <math.h>

t_vec3  vec3_normalize(t_vec3 v)
{
    t_vec3  ret;
    float   len;

    len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    ret.x = v.x / len;
    ret.y = v.y / len;
    ret.z = v.z / len;
    return (ret);
}