/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:16:07 by niragne           #+#    #+#             */
/*   Updated: 2018/03/07 15:58:40 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

SDL_Surface *load_bmp(char *name)
{
    SDL_Surface *ret;
    void        *tmp = NULL;

    ret = IMG_Load(name);
    int size = ret->pitch * ret->h;
    int i = ret->h - 1;
    if (!(tmp = malloc(size)))
        exit(1);
    while (i >= 0)
    {
        memcpy(tmp + i * ret->pitch, ret->pixels + (ret->h - 1 - i) * ret->pitch, ret->pitch);
        i--;
    }
    ret->pixels = tmp;
    return (ret);
} 