/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_id_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:32:52 by niragne           #+#    #+#             */
/*   Updated: 2018/02/14 17:35:47 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat3    mat4_id_new(void)
{
    t_mat4 ret;

    if (!(ret = malloc(sizeof(float) * 16))) //
        exit(1);
    bzero(ret, sizeof(float) * 16);
    ret[0] = 1;
    ret[5] = 1;
    ret[10] = 1;
    ret[15] = 1;
    return (ret);
}