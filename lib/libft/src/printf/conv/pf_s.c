/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:57:13 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:17:38 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_s(va_list arg, t_pfflags *flags)
{
	char		*str;
	t_uint32	size;

	str = va_arg(arg, char *);
	size = ft_strlen(str);
	if (flags->tags.prec && flags->prec < size)
		size = flags->prec;
	flags->blank -= size;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		g_pf_buff(str, size);
	}
	else
	{
		g_pf_buff(str, size);
		pf_fill(flags->blank, ' ');
	}
	return (size + flags->blank);
}
