/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:08:45 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 15:14:52 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4    mat4_new(void)
{
    t_mat4 ret;

    if (!(ret = ft_memalloc(sizeof(float) * 16)))
        exit(1);
    return (ret);
}