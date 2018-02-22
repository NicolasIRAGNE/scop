/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:34:49 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:32:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"
#include <stdlib.h>
#include "put.h"

static void	ft_delchar(char **str, char c)
{
	while (**str == c)
		(*str)++;
}

static void	ft_delnum(char **str, char c)
{
	while (**str != c && **str != '\0')
		(*str)++;
}

static int	ft_countnbr(char *str, char c)
{
	int		nb;
	int		i;

	if (*str == '\0')
		return (0);
	nb = 1;
	i = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			nb++;
		i++;
	}
	return (nb);
}

int			*ft_atoi_split(char *str, char c)
{
	int		*tab;
	int		nbnum;
	int		i;

	ft_delchar(&str, c);
	nbnum = ft_countnbr(str, c) + 1;
	if (!(tab = (int *)malloc(sizeof(*tab) * nbnum)))
		ft_afferror("error malloc in ft_atoi_split");
	tab[0] = nbnum;
	i = 1;
	while (i < nbnum)
	{
		tab[i] = ft_atoi(str);
		ft_delnum(&str, c);
		ft_delchar(&str, c);
		i++;
	}
	return (tab);
}
