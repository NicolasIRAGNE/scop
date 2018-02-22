/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_maj_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:56:16 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:19:15 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_maj_s(va_list arg, t_pfflags *flags)
{
	wchar_t		*str;
	t_uint32	size;

	str = va_arg(arg, wchar_t *);
	size = ft_wstrlen(str);
	flags->blank -= size;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		while (*str)
			pf_putchar(*str++);
	}
	else
	{
		while (*str)
		{
			pf_putchar(*str);
			str++;
		}
		pf_fill(flags->blank, ' ');
	}
	return (size + flags->blank);
}
