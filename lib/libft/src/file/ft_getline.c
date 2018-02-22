/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:19:56 by iburel            #+#    #+#             */
/*   Updated: 2018/02/19 18:05:33 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "mem.h"
#include <stdlib.h>
#include <unistd.h>

static void	init(t_file *file)
{
	if (file->i >= file->len)
	{
		file->i = 0;
		file->len = read(file->fd, file->buf, BUFF_SIZE);
	}
}

static int	check_buffer(char **line, t_file *file, int size)
{
	char	*tmp;

	if ((tmp = ft_memchr(file->buf + file->i, '\n', size)))
	{
		size = tmp - file->buf - file->i;
		if (!(*line = malloc(size + 1)))
			return (-1);
		ft_memcpy(*line, file->buf + file->i, size);
		(*line)[size] = '\0';
		file->i += size + 1;
		return (1);
	}
	return (0);
}

static int	ifnewline(char **line, t_file *file, int size_line, int size)
{
	if (!(*line = realloc(*line, size_line + size + 1)))
		return (-1);
	ft_memcpy(*line + size_line, file->buf, size);
	(*line)[size_line + size] = '\0';
	file->i = size + 1;
	return (1);
}

static int	search_newline(char **line, t_file *file, int size)
{
	int		size_line;
	char	*tmp;

	size_line = size;
	while (1)
	{
		if ((file->len = read(file->fd, file->buf, BUFF_SIZE)) == -1)
			return (-1);
		if (file->len == 0)
		{
			(*line)[size_line] = '\0';
			file->i = 0;
			return (1);
		}
		if ((tmp = ft_memchr(file->buf, '\n', file->len)))
		{
			size = tmp - file->buf;
			return (ifnewline(line, file, size_line, size));
		}
		if (!(*line = realloc(*line, size_line + BUFF_SIZE + 1)))
			return (-1);
		ft_memcpy(*line + size_line, file->buf, BUFF_SIZE);
		size_line += BUFF_SIZE;
	}
}

int			ft_getline(char **line, t_file *file)
{
	int		size;
	int		tmp;

	init(file);
	if (file->len <= 0)
		return (file->len);
	size = file->len - file->i;
	if ((tmp = check_buffer(line, file, size)))
		return (tmp);
	if (!(*line = malloc(size + 1)))
		return (-1);
	ft_memcpy(*line, file->buf + file->i, size);
	return (search_newline(line, file, size));
}
