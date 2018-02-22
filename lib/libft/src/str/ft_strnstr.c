/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:25:08 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:29:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && len <= n)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
