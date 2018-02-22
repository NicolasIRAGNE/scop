/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplxdiv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 21:43:37 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:24:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cplx.h"

t_cplx	ft_cplxdiv(t_cplx z1, t_cplx z2)
{
	t_cplx	ret;

	ret.re = (z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im);
	ret.im = (z1.im * z2.re - z1.re * z2.im) / (z2.re * z2.re + z2.im * z2.im);
	return (ret);
}
