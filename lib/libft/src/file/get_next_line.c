/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:39:44 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:59:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "str.h"
#include "put.h"
#include "mem.h"
#include <unistd.h>
#include <stdlib.h>

static char		*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tmp;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (size + 2))))
		ft_afferror("error malloc in GNL");
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, s2);
	tmp[size + 1] = '\0';
	ft_strdel(&s1);
	return (tmp);
}

static int		reset_rest(char *rest[OPEN_MAX], int fd)
{
	free(rest[fd]);
	rest[fd] = NULL;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*rest[OPEN_MAX];
	t_gnl			gnl;
	int				ret;

	ret = 1;
	if (fd < 0)
		return (reset_rest(rest, -fd));
	if (rest[fd] == NULL)
		rest[fd] = ft_strnew(0);
	while (ret != -1)
	{
		if ((gnl.tmp = ft_strchr(rest[fd], '\n')) ||
				((gnl.tmp = ft_strchr(rest[fd], '\0')) && !ret))
		{
			*(gnl.tmp) = '\0';
			*line = ft_strdup(rest[fd]);
			ft_memmove(rest[fd], gnl.tmp + 1, ft_strlen(gnl.tmp + 1) + 1);
			return (**line || (!**line && ret));
		}
		if ((ret = read(fd, gnl.buf, BUFF_SIZE)) == -1)
			ft_afferror("error read file in GNL");
		gnl.buf[(unsigned)ret] = '\0';
		rest[fd] = ft_strjoin_gnl(rest[fd], gnl.buf);
	}
	return (-1);
}
