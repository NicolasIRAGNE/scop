/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:37:09 by iburel            #+#    #+#             */
/*   Updated: 2018/02/16 19:37:34 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		(*g_pf_buff)(char *, int);
t_uint64	(*g_pf_utype[7])(va_list) =
{
	pf_ushort,
	pf_u2short,
	pf_ulong,
	pf_u2long,
	pf_uintmax,
	pf_size,
	pf_uint
};

t_int64		(*g_pf_type[7])(va_list) =
{
	pf_short,
	pf_2short,
	pf_long,
	pf_2long,
	pf_intmax,
	pf_ssize,
	pf_int
};
