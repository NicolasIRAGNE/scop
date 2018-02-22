/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:45 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:41:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_prec(char *format, va_list arg, t_pfflags *flags)
{
	int		n;

	(void)arg;
	format++;
	n = 0;
	while (*format >= '0' && *format <= '9')
	{
		n = n * 10 + *format - '0';
		format++;
	}
	flags->prec = n;
	flags->tags.prec = 1;
	return (format);
}
