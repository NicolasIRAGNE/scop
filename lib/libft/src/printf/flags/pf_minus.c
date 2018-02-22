/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:35 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:13:24 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_minus(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->tags.minus = 1;
	return (format + 1);
}
