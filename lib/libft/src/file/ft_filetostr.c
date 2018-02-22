/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:00:19 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:53:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "str.h"
#include "put.h"
#include <unistd.h>
#include <fcntl.h>

char	*ft_filetostr(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_afferror("error open in ft_filetostr");
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			ft_afferror("error read in ft_filetostr");
		buf[ret] = '\0';
		str = ft_strjoin_free(str, buf, 'L');
	}
	if (close(fd) == -1)
		ft_afferror("error close in ft_filetostr");
	return (str);
}
