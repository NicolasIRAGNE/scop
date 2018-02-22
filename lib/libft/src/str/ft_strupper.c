/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:22:10 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:16:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "char.h"

char	*ft_strupper(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		if (ft_islower(*str))
			*str -= 32;
		str++;
	}
	return (ret);
}
