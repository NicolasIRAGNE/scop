/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/04 12:49:34 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*fd_to_str(int fd)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	*ret;
	int		rd;

	i = 0;
	ret = NULL;
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd == -1)
			return (NULL);
		buf[BUFF_SIZE] = '\0';
		ret = ft_realloc(ret, sizeof(char) * BUFF_SIZE * (i + 1) + 1,
		BUFF_SIZE * i);
		ft_strncat(ret, buf, rd);
		i++;
	}
	return (ret);
}
