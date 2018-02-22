/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:19:33 by iburel            #+#    #+#             */
/*   Updated: 2018/02/10 14:35:07 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_itoa(char *str, t_int64 n)
{
	int		size;
	t_int64	div;
	int		i;

	size = 1;
	div = -1;
	while (div >= n / 10)
	{
		div *= 10;
		size++;
	}
	i = 0;
	while (div < 0)
	{
		str[i] = n / div + '0';
		n %= div;
		div /= 10;
		i++;
	}
	return (size);
}
