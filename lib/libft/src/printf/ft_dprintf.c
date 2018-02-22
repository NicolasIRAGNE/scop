/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:44:25 by root              #+#    #+#             */
/*   Updated: 2018/02/18 18:15:51 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, char *format, ...)
{
	va_list arg;
	int		done;

	va_start(arg, format);
	done = ft_vdprintf(fd, format, arg);
	va_end(arg);
	return (done);
}
