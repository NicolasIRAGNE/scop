/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:20:58 by iburel            #+#    #+#             */
/*   Updated: 2018/02/10 16:09:48 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdlib.h>
#include <fcntl.h>

t_file	*ft_fopen(char *filename, int mode)
{
	t_file	*file;

	if (!(file = malloc(sizeof(*file))))
		return (NULL);
	if ((file->fd = open(filename, mode)) == -1)
		return (NULL);
	file->len = 0;
	file->i = 0;
	return (file);
}
