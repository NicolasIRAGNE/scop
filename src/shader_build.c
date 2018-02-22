/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:53:11 by niragne           #+#    #+#             */
/*   Updated: 2018/02/14 11:53:15 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static char *file_to_str(char *file)
{
    char    *buf;
    int     fd;
    int     ret;

    if (!(buf = malloc(sizeof(*buf) * 10000)))
    {
        printf("error malloc buffer for build %s\n", file);
        return (NULL);
    }
    if ((fd = open(file, O_RDONLY)) == -1)
    {
        printf("error open %s\n", file);
        return (NULL);
    }
    if ((ret = read(fd, buf, 10000)) == -1)
    {
        printf("error read %s\n", file);
        return (NULL);
    }
    if (ret == 100000)
    {
        printf("%s too big\n", file);
        return (NULL);
    }
    close(fd);
    buf[ret] = 0;
    return (buf);
}

static int  check_shader(GLuint shader)
{
    GLint   error;
    GLint   size;
    char    *str;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &error);
    if (!error)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
        if (!(str = malloc(sizeof(*str) * (size + 1))))
        {
            printf("error malloc error shader\n");
            return (0);
        }
        glGetShaderInfoLog(shader, size, &size, str);
        str[size] = 0;
        printf("%s\n", str);
        free(str);
        return (0);
    }
    return (1);
}

int         shader_build(GLuint *shader, GLenum type, char *file)
{
    char    *buf;

    if (!(*shader = glCreateShader(type)))
    {
        printf("error bad type shader\n");
        return (0);
    }
    if (!(buf = file_to_str(file)))
        return (0);
    glShaderSource(*shader, 1, (const char **)&buf, 0);
    glCompileShader(*shader);
    free(buf);
    if (!check_shader(*shader))
        return (0);
    return (1);
}