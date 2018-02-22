/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:27 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:13:53 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_hashtag(char *format, va_list arg, t_pfflags *flags)
{
	(void)arg;
	flags->tags.hashtag = 1;
	return (format + 1);
}
