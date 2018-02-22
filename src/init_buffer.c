/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:31:43 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 15:51:57 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

GLuint init_buffer(void)
{
    GLuint vao;

	float vertices[] =
	{
		-1.f, -1.f, -1.f,   1.f, -1.f, -1.f,   1.f, 1.f, -1.f,
		-1.f, -1.f, -1.f,   -1.f, 1.f, -1.f,   1.f, 1.f, -1.f,

		1.f, -1.f, 1.f,   1.f, -1.f, -1.f,   1.f, 1.f, -1.f,
		1.f, -1.f, 1.f,   1.f, 1.f, 1.f,   1.f, 1.f, -1.f,

		-1.f, -1.f, 1.f,   1.f, -1.f, 1.f,   1.f, -1.f, -1.f,
		-1.f, -1.f, 1.f,   -1.f, -1.f, -1.f,   1.f, -1.f, -1.f,

		-1.f, -1.f, 1.f,   1.f, -1.f, 1.f,   1.f, 1.f, 1.f,
		-1.f, -1.f, 1.f,   -1.f, 1.f, 1.f,   1.f, 1.f, 1.f,

		-1.f, -1.f, -1.f,   -1.f, -1.f, 1.f,   -1.f, 1.f, 1.f,
		-1.f, -1.f, -1.f,   -1.f, 1.f, -1.f,   -1.f, 1.f, 1.f,

		-1.f, 1.f, 1.f,   1.f, 1.f, 1.f,   1.f, 1.f, -1.f,
		-1.f, 1.f, 1.f,   -1.f, 1.f, -1.f,   1.f, 1.f, -1.f
	};

	float coordTexture[] =
	{
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