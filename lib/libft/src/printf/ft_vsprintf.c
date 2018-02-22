/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:03:49 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:37:42 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *str, char *format, va_list arg)
{
	int		done;
	int		ret;
	char	*tmp;

	spf_init_buff(str);
	g_pf_buff = spf_buff;
	done = 0;
	tmp = format;
	while (*format)
	{
		if (*format == '%')
		{
			g_pf_buff(tmp, format - tmp);
			done += format - tmp;
			ret = pf_conv(&format, arg);
			done += ret;
			tmp = format + 1;
		}
		format++;
	}
	g_pf_buff(tmp, format - tmp);
	g_pf_buff("", 1);
	done += format - tmp;
	return (done);
}
