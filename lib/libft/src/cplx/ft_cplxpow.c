/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplxpow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:18:08 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:24:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cplx.h"

t_cplx	ft_cplxpow(t_cplx z, int pow)
{
	t_cplx	ret;
	int		i;

	if (pow <= 0)
		return (ft_cplxnew(0, 0));
	if (pow == 1)
		return (z);
	ret = z;
	i = 1;
	while ((i <<= 1) <= pow)
		ret = ft_cplxmult(ret, ret);
	i >>= 1;
	while (i++ < pow)
		ret = ft_cplxmult(ret, z);
	return (ret);
}
