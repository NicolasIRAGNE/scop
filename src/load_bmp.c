/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   C0ted: 2018/03/07 15:16:07 by niragne           #+#    #+#             */
/*   Updated: 2018/03/17 18:21:23 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
 
t_bmp *reverse(t_bmp *img)
{
    void    *tmp;
    int i = img->info.h - 1;
    int pitch = img->info.w * img->info.bits / 8;
    
    if (!(tmp = malloc(img->info.imagesize)))
        exit(1);
    while (i > 0)
    {
        memcpy(tmp + i * pitch, img->pixels + (img->info.h - i) * pitch, pitch);
        i--;
    }
    img->pixels = tmp;
    return (img);
} 
/*
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
    rd = read(fd, (char*)&ret->header + 2, 14);
    if (rd == -1)
        exit(printf("failed to read %s\n", name));
    else if (rd != 14)
        exit(printf("format error: %s\n", name));
    rd = read(fd, &ret->info, 40);
    if (rd == -1)
        exit(printf("failed to read %s\n", name));
    else if (rd != 40)
        exit(printf("format error: %s\n", name));
    char buf[6000];
    read(fd, buf, ret->header.offset - 54);
    if (ret->info.h < 0)
        ret->info.h = -ret->info.h;
    if (!ret->info.imagesize)
        ret->info.imagesize = ret->info.h * ret->info.w;
    ret->pixels = malloc(ret->info.imagesize);
    rd = read(fd, ret->pixels, ret->info.imagesize);
    printf("%d\n", rd);
    // exit(1);
    // t_uint32 i = 0;
    // while (i < ret->info.imagesize / 4)
    // {
        // if ((ret->pixels[i] & 0xff) > 0x80)
            // ret->pixels[i] = 0;
        // i++;
    // }
    reverse(ret);
    close(fd);
    return (ret);
}*/


t_bmp   *load_bmp(char *name)
{
    t_bmp   *ret;
    char    *map;
    int     fd;
    struct stat buf;

    if ((fd = open(name, O_RDONLY)) == -1)
    {
        printf("error open %s\n", name);
        exit(4);
    }
    fstat(fd, &buf);
    if (!(map = mmap(NULL, buf.st_size, PROT_WRITE, MAP_PRIVATE, fd, 0)))
    {
        printf("error mmap %s\n", map);
        exit(5);
    }
    ret = (t_bmp*)(map - 2);
    ret->pixels = map + ret->header.offset;
    return (ret);
}

