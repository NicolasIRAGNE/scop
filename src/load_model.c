/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:56:34 by niragne           #+#    #+#             */
/*   Updated: 2018/03/19 16:29:09 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_obj   *load_model(char *name)
{
    t_obj   *ret = NULL;
    FILE    *fd;
    char    str[2048];
    
    ret = malloc(sizeof(t_obj));
    if (!(fd = fopen(name, "r")))
    {
        printf("error open %s\n", name);
        exit(4);
    }
    ret->vertices = malloc(sizeof(float) * 3);
    ret->coord_texture = malloc(sizeof(float) * 2);
    ret->normal = malloc(sizeof(float) * 3);
    ret->face = malloc(sizeof(int) * 9);
    ret->nb_vertices = 0;
    ret->nb_coords = 0;
    ret->nb_normal = 0;
    ret->nb_face = 0;
    while (fgets(str, 2048, fd))
    {
        if (str[0] == 'v' && str[1] == ' ')
        {
            ret->vertices = realloc(ret->vertices, (ret->nb_vertices + 3) * sizeof(float));
            if ((sscanf(str + 2, "%f %f %f", ret->vertices + ret->nb_vertices, ret->vertices + ret->nb_vertices + 1, ret->vertices + ret->nb_vertices + 2)) != 3)
                exit(2);
            ret->nb_vertices += 3;
        }
        else if (str[0] == 'v' && str[1] == 't')
        {
            ret->coord_texture = realloc(ret->coord_texture, (ret->nb_coords + 2) * sizeof(float));
            if ((sscanf(str + 3, "%f %f", ret->coord_texture + ret->nb_coords, ret->coord_texture + ret->nb_coords + 1)) != 2)
                exit(2);
            ret->nb_coords += 2;
        }
        else if (str[0] == 'v' && str[1] == 'n')
        {
            ret->normal = realloc(ret->normal, (ret->nb_normal + 3) * sizeof(float));
            if ((sscanf(str + 3, "%f %f %f", ret->normal + ret->nb_normal, ret->normal + ret->nb_normal + 1, ret->normal + ret->nb_normal + 2)) != 3)
                exit(2);
            ret->nb_normal += 3;
        }
        else if (str[0] == 'f' && str[1] == ' ')
        {
            ret->face = realloc(ret->face, (ret->nb_face + 9) * sizeof(int));
            if ((sscanf(str + 2, "%d/%d/%d %d/%d/%d %d/%d/%d\n", ret->face + ret->nb_face, ret->face + ret->nb_face + 1, ret->face + ret->nb_face + 2, ret->face + ret->nb_face + 3, ret->face + ret->nb_face + 4, ret->face + ret->nb_face + 5, ret->face + ret->nb_face + 6, ret->face + ret->nb_face + 7, ret->face + ret->nb_face + 8) != 9))
                exit(2);
            ret->nb_face += 9;
        }
    }
    return (ret);
}