/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:44:25 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:40:44 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sprintf(char *str, char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vsprintf(str, format, arg);
	va_end(arg);
	return (done);
}
