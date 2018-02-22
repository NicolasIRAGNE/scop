/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_id_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:30:37 by niragne           #+#    #+#             */
/*   Updated: 2018/02/14 17:35:31 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat3    mat3_id_new(void)
{
    t_mat4 ret;

    if (!(ret = malloc(sizeof(float) * 9))) //
        exit(1);
    bzero(ret, sizeof(float) * 9);
    ret[0] = 1;
    ret[4] = 1;
    ret[8] = 1;
    return (ret);
}