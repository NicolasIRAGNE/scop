/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:50:47 by niragne           #+#    #+#             */
/*   Updated: 2018/02/16 18:18:23 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static int	check_prog(GLuint prog)
{
    GLint   error;
    GLint   size;
    char    *str;

    glGetProgramiv(prog, GL_LINK_STATUS, &error);
    if (!error)
    {
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
        if (!(str = malloc(sizeof(*str) * (size + 1))))
        {
            printf("error malloc for error build shaders\n");
            return (0);
        }
        glGetProgramInfoLog(prog, size, &size, str);
        str[size] = 0;
        printf("error: %s\n", str);
        free(str);
        glDeleteProgram(prog);
        return (0);
    }
    return (1);
}

GLuint		create_prog(char *vertex_shader, char *fragment_shader)
{
    GLuint  vert;
    GLuint  frag;
    GLuint  prog;

    if (!(shader_build(&vert, GL_VERTEX_SHADER, vertex_shader)))
        return (UINT_MAX);
    if (!(shader_build(&frag, GL_FRAGMENT_SHADER, fragment_shader)))
        return (UINT_MAX);
    prog = glCreateProgram();
    glAttachShader(prog, vert);
    glAttachShader(prog, frag);
    glBindAttribLocation(prog, 0, "in_Vertex");
    glBindAttribLocation(prog, 1, "coordTexture");
    glLinkProgram(prog);
    if (!check_prog(prog))
        return (UINT_MAX);
    return (prog);
}
