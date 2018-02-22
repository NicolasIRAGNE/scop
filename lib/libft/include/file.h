/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:44:59 by root              #+#    #+#             */
/*   Updated: 2018/02/10 16:07:50 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# define BUFF_SIZE 65535

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_gnl	t_gnl;
typedef struct s_file	t_file;

struct	s_file
{
	int		fd;
	char	buf[BUFF_SIZE];
	int		len;
	int		i;
};

struct	s_gnl
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
};

char	*ft_filetostr(char *file);
int		get_next_line(const int fd, char **line);
t_file	*ft_fopen(char *filename, int mode);
int		ft_getline(char **line, t_file *file);

#endif
