/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:01:49 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:33:52 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*(*g_f[256])(char *, va_list, t_pfflags *) =
{
	['#'] = pf_hashtag,
	['0'] = pf_zero,
	['-'] = pf_minus,
	[' '] = pf_space,
	['+'] = pf_plus,
	['h'] = pf_h,
	['l'] = pf_l,
	['j'] = pf_j,
	['z'] = pf_z,
	['1'] = pf_blank,
	['2'] = pf_blank,
	['3'] = pf_blank,
	['4'] = pf_blank,
	['5'] = pf_blank,
	['6'] = pf_blank,
	['7'] = pf_blank,
	['8'] = pf_blank,
	['9'] = pf_blank,
	['.'] = pf_prec,
	['*'] = pf_star
};

char		*pf_tags(char *format, va_list arg, t_pfflags *flags)
{
	while (g_f[(int)*format])
		format = g_f[(int)*format](format, arg, flags);
	return (format);
}
