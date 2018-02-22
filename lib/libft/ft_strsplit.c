/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/04 14:02:31 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_countwds(char const *s, char c)
{
	size_t	i;
	int		j;
	char	test;
	char	test1;

	i = 0;
	j = 1;
	while (i != ft_strlen(s))
	{
		while (s[i])
		{
			i++;
			test = s[i];
			test1 = s[i + 1];
			if ((test == c) && test1 != c)
				j++;
		}
	}
	return (j);
}

static	int		ft_ltr(char const *s, int i, char c)
{
	int j;

	j = 0;
	while ((s[i] != c) && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (!s || (tab = malloc(sizeof(char *) * (ft_countwds(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if ((tab[j] = malloc(sizeof(char) * (ft_ltr(s, i, c) + 1))) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
