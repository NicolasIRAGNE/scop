/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:25:47 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:29:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	char	*tmp;

	if (*s2 == '\0')
		return ((char *)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	tmp = (char *)s1;
	while (*tmp)
	{
		if (*tmp == *s2)
		{
			i = 0;
			while (tmp[i] == s2[i] && s2[i])
				i++;
			if (s2[i] == '\0')
				return (tmp);
		}
		tmp++;
	}
	return (NULL);
}
