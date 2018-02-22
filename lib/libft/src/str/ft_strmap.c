/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:23:59 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:17:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*tmp;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = (*f)(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
