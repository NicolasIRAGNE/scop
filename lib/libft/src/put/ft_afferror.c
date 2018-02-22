/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afferror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:18:18 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:15:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"
#include "str.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_afferror(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}
