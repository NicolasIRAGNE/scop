/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_id_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:32:52 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 14:43:20 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4    mat4_id_new(void)
{
    t_mat4 ret;

    if (!(ret = malloc(sizeof(float) * 16))) //
        exit(1);
    bzero(ret, sizeof(float) * 16);
    ret[0] = 1.f;
    ret[5] = 1.f;
    ret[10] = 1.f;
    ret[15] = 1.f;
    return (ret);
}