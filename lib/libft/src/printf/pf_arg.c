/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:00:28 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:34:40 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	(*g_f[256])() =
{
	['a'] = pf_a,
	['A'] = pf_maj_a,
	['b'] = pf_b,
	['B'] = pf_maj_b,
	['c'] = pf_c,
	['C'] = pf_maj_c,
	['d'] = pf_d,
	['D'] = pf_maj_d,
	['e'] = pf_e,
	['E'] = pf_maj_e,
	['f'] = pf_f,
	['F'] = pf_maj_f,
	['g'] = pf_g,
	['G'] = pf_maj_g,
	['i'] = pf_i,
	['I'] = pf_maj_i,
	['k'] = pf_k,
	['o'] = pf_o,
	['O'] = pf_maj_o,
	['p'] = pf_p,
	['s'] = pf_s,
	['S'] = pf_maj_s,
	['u'] = pf_u,
	['U'] = pf_maj_u,
	['x'] = pf_x,
	['X'] = pf_maj_x,
	['%'] = pf_per
};

int			pf_arg(char c, va_list arg, t_pfflags *flags)
{
	if (!g_f[(int)c])
		return (-1);
	return (g_f[(int)c](arg, flags));
}
