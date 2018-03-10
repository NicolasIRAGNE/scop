/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:16:07 by niragne           #+#    #+#             */
/*   Updated: 2018/03/10 18:30:36 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

// SDL_Surface *load_bmp(char *name)
// {
//     SDL_Surface *ret;
//     void        *tmp = NULL;

//     ret = IMG_Load(name);
//     int size = ret->pitch * ret->h;
//     int i = ret->h - 1;
//     if (!(tmp = malloc(size)))
//         exit(1);
//     while (i >= 0)
//     {
//         memcpy(tmp + i * ret->pitch, ret->pixels + (ret->h - 1 - i) * ret->pitch, ret->pitch);
//         i--;
//     }
//     ret->pixels = tmp;
//     return (ret);
// } 

t_bmp   *load_bmp(char *name)
{
    t_bmp    *ret;
    SDL_Surface *testos;
    int rd;
    int fd;

    ret = malloc(sizeof(t_bmp));
    testos = IMG_Load(name);
    if ((fd = open(name, O_RDONLY)) == -1)
        exit(printf("failed to open %s\n", name));
    printf("fd %d\n", fd);
    rd = read(fd, (char*)&ret->header + 2, 14);
    printf("rd %d\n", rd);    
    if (rd == -1)
        exit(printf("failed to read %s\n", name));
    else if (rd != 14)
        exit(printf("format error: %s\n", name));
    rd = read(fd, &ret->info, 40);
    if (rd == -1)
        exit(printf("failed to read %s\n", name));
    else if (rd != 40)
        exit(printf("format error: %s\n", name));
    ret->pixels = malloc(ret->header.size);
    read(fd, ret->pixels, ret->header.size);
    // ret->pixels = testos->pixels;
    close(fd);
    return (ret);
}