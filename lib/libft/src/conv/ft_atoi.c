/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:14:12 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:34:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"
#include "char.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		nb;

	nb = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 - '0' + *str;
		str++;
	}
	return (nb * neg);
}
