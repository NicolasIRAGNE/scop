/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:00:04 by niragne           #+#    #+#             */
/*   Updated: 2018/02/14 18:44:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat3    mat3_new(void)
{
    t_mat3 ret;

    if (!(ret = ft_memalloc(sizeof(float) * 9)))
    {
        exit(1);
    }
    return (ret);
}