/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:54:44 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:27:54 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_c(va_list arg, t_pfflags *flags)
{
	char	c;

	c = va_arg(arg, int);
	flags->blank -= 1;
	flags->blank *= (flags->blank <= INT_MAX);
	if (!flags->tags.minus)
	{
		pf_fill(flags->blank, ' ');
		g_pf_buff(&c, 1);
	}
	else
	{
		g_pf_buff(&c, 1);
		pf_fill(flags->blank, ' ');
	}
	return (flags->blank + 1);
}
