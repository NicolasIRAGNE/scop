/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:25:33 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:18:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

static void		ft_del_space(char **s, char c)
{
	while (**s == c && **s != '\0')
		*s = *s + 1;
}

static size_t	ft_nb_words(char *s, char c)
{
	size_t	nb_words;
	size_t	i;

	if (*s == '\0')
		return (0);
	nb_words = 1;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			nb_words++;
		i++;
	}
	return (nb_words);
}

static size_t	ft_wordlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		*ft_worddup(char **s, char c)
{
	char	*tmp;
	size_t	i;
	size_t	size;

	size = ft_wordlen(*s, c);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp[i] = (*s)[i];
		i++;
	}
	tmp[i] = '\0';
	*s = *s + size;
	return (tmp);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	char	*tmp;
	size_t	nb_words;
	size_t	i;

	if (s == NULL)
		return (NULL);
	tmp = (char *)s;
	ft_del_space(&tmp, c);
	nb_words = ft_nb_words(tmp, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		tab[i] = ft_worddup(&tmp, c);
		ft_del_space(&tmp, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
