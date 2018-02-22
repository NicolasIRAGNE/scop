/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:20:34 by root              #+#    #+#             */
/*   Updated: 2018/02/16 19:33:36 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_put_d(t_pfflags *flags, int size, char sign, char *str)
{
	if (!flags->tags.minus)
	{
		if (!flags->tags.zero)
		{
			pf_fill(flags->blank, ' ');
			sign ? g_pf_buff(&sign, 1) : 1;
			pf_fill(flags->prec, '0');
			g_pf_buff(str, size);
		}
		else
		{
			if (sign)
				g_pf_buff(&sign, 1);
			pf_fill(flags->blank + flags->prec, '0');
			g_pf_buff(str, size);
		}
	}
	else
	{
		if (sign)
			g_pf_buff(&sign, 1);
		pf_fill(flags->prec, '0');
		g_pf_buff(str, size);
		pf_fill(flags->blank, ' ');
	}
}

int			pf_d(va_list arg, t_pfflags *flags)
{
	char	str[20];
	t_int64	n;
	int		size;
	char	sign;
	int		test;

	sign = flags->tags.space * ' ' + flags->tags.plus * '+';
	n = g_pf_type[flags->type](arg);
	if (n >= 0)
		n = -n;
	else
		sign = '-';
	size = pf_itoa(str, n);
	test = (sign != 0);
	flags->prec -= size + test;
	flags->prec *= (flags->prec <= INT_MAX);
	flags->blank -= size + test + flags->prec;
	flags->blank *= (flags->blank <= INT_MAX);
	pf_put_d(flags, size, sign, str);
	return (size + flags->prec + flags->blank + test);
}
