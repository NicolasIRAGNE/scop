/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplxsqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:17:27 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:38:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cplx.h"
#include <math.h>

t_cplx	ft_cplxsqrt(t_cplx z)
{
	t_cplx	ret;

	if ((ret.re = sqrt((z.re + sqrt(z.re * z.re + z.im * z.im)) / 2)))
		ret.im = z.im / (2 * ret.re);
	else
		ret.im = 0;
	if (z.re < 0)
	{
		ret.re *= -1;
		ret.im *= -1;
	}
	return (ret);
}
