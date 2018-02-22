/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:25 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:14:30 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_h(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	if (flags->type == H)
		flags->type = HH;
	else
		flags->type = H;
	return (format + 1);
}
