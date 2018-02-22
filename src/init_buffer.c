/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:31:43 by niragne           #+#    #+#             */
/*   Updated: 2018/02/18 17:43:38 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

GLuint init_buffer(void)
{
    GLuint vao;


float vertices[] = {-1, -1, -1,   1, -1, -1,   1, 1, -1,     // Face 1
                    -1, -1, -1,   -1, 1, -1,   1, 1, -1,     // Face 1

                    1, -1, 1,   1, -1, -1,   1, 1, -1,       // Face 2
                    1, -1, 1,   1, 1, 1,   1, 1, -1,         // Face 2

                    -1, -1, 1,   1, -1, 1,   1, -1, -1,      // Face 3
                    -1, -1, 1,   -1, -1, -1,   1, -1, -1,    // Face 3

                    -1, -1, 1,   1, -1, 1,   1, 1, 1,        // Face 4
                    -1, -1, 1,   -1, 1, 1,   1, 1, 1,        // Face 4

                    -1, -1, -1,   -1, -1, 1,   -1, 1, 1,     // Face 5
                    -1, -1, -1,   -1, 1, -1,   -1, 1, 1,     // Face 5

                    -1, 1, 1,   1, 1, 1,   1, 1, -1,         // Face 6
                    -1, 1, 1,   -1, 1, -1,   1, 1, -1};      // Face 6

    float coordTexture[] = {
                            0.f, 1.f,   1.f, 1.f,   1.f, 0.f,
                            0.f, 1.f,   0.f, 0.f,   1.f, 0.f,
                            0.f, 1.f,   1.f, 1.f,   1.f, 0.f,
                            0.f, 1.f,   0.f, 0.f,   1.f, 0.f,
                            0.f, 1.f,   1.f, 1.f,   1.f, 0.f,
                            0.f, 1.f,   0.f, 0.f,   1.f, 0.f,
                            0.f, 1.f,   1.f, 1.f,   1.f, 0.f,
                            0.f, 1.f,   0.f, 0.f,   1.f, 0.f,
                            0.f, 1.f,   1.f, 1.f,   1.f, 0.f,
                            0.f, 1.f,   0.f, 0.f,   1.f, 0.f,
                            0.f, 1.f,   1.f, 1.f,   1.f, 0.f,
                            0.f, 1.f,   0.f, 0.f,   1.f, 0.f
                            };
    glGenBuffers(1, &main_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, main_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(coordTexture), NULL, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(coordTexture), coordTexture);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, main_vbo);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glEnableVertexAttribArray(0); //j'active (il est activé (c'est bien))
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertices));
            glEnableVertexAttribArray(1); //j'active (il est activé (c'est bien))            
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return (1);
}