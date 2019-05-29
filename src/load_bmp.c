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
    void    *tmp2;
    int     pitch = img->info.w * img->info.bits / 8;
    int     j = 0;
    
    tmp2 = img->pixels;
    img->pixels = img->pixels + pitch * (img->info.h - 1);
    if (!(tmp = malloc(img->info.imagesize)))
        exit(1);
    while (j < img->info.h)
    {
        memcpy(tmp, img->pixels, pitch);
        tmp += pitch;
        img->pixels -= pitch;
        j++;
    }
    tmp -= j * pitch;
    img->pixels = tmp;
    free(tmp2);
    return (img);
} 

t_bmp   *load_bmp(char *name)
{
    t_bmp    *ret;
    int rd;
    int fd;
    int flag;

	flag = 0;
    ret = malloc(sizeof(t_bmp));
    if ((fd = open(name, O_RDONLY)) == -1)
        exit(printf("failed to open %s\n", name));
    rd = read(fd, (char*)&ret->header + 2, 14);
    if (rd == -1)
        exit(printf("failed to read %s\n", name));
    else if (rd != 14 || ret->header.type != 0x4d42)
        exit(printf("format error: %s\n", name));
    rd = read(fd, &ret->info, 40);
    if (rd == -1)
        exit(printf("failed to read %s\n", name));
    else if (rd != 40)
        exit(printf("format error: %s\n", name));
    if (ret->info.h < 0)
    {
		ret->info.h = -ret->info.h;
		flag = 1;
    }
    if (!ret->info.imagesize)
    {
		ret->info.imagesize = ret->info.h * ret->info.w * 3;
    }
    if (!(ret->pixels = malloc(ret->info.imagesize)))
		exit(printf("malloc error"));
    printf("FILE NAME %s FILE DIMS %d * %d, SIZE %d\n", name, ret->info.w, ret->info.h, ret->info.imagesize);
    char buf[512];
    read(fd, buf, ret->header.offset - 54);
    rd = read(fd, ret->pixels, ret->info.imagesize);
	int bite = 0;
    while (bite < rd)
    {
      //  printf("%x ", ((unsigned char *) ret->pixels) [bite]);
        bite++;
    }
    printf("\n");
    // exit(1);
    //if (flag)
    //	reverse(ret);
    close(fd);
    return (ret);
}


/*t_bmp   *load_bmp(char *name)
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
    if ((map = mmap(NULL, buf.st_size, PROT_WRITE, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
        printf("error mmap %s\n", map);
        exit(5);
    }
    ret = (t_bmp*)(map - 2);
    ret->pixels = map + ret->header.offset;
    return (ret);
}*/
