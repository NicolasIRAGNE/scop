/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:59:59 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:41:58 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vprintf(format, arg);
	va_end(arg);
	return (done);
}
