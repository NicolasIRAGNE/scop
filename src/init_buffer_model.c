/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer_model.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:20:18 by niragne           #+#    #+#             */
/*   Updated: 2018/03/19 18:00:34 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

GLuint init_buffer_model(t_obj *obj)
{
    	GLuint vao;
	    GLuint	main_vbo;
        float *trucs;
        unsigned long i = 0;
        int vertexIndex;
        int vertexIndex2;
        int vertexIndex3;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    	glGenBuffers(1, &main_vbo);
    	glBindBuffer(GL_ARRAY_BUFFER, main_vbo);
        	glBufferData(GL_ARRAY_BUFFER, obj->nb_vertices * sizeof(float), obj->vertices, GL_STATIC_DRAW);
            trucs = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
            while (i < obj->nb_face / 3)
            {
                vertexIndex = obj->face[i * 3];
                vertexIndex2 = obj->face[(i + 1) * 3];
                vertexIndex3 = obj->face[(i + 2) * 3];
                trucs[i * 3 + 0] = obj->vertices[(vertexIndex - 1) * 3 + 0];
                trucs[i * 3 + 1] = obj->vertices[(vertexIndex - 1) * 3 + 1];
                trucs[i * 3 + 2] = obj->vertices[(vertexIndex - 1) * 3 + 2];
                trucs[i * 3 + 3] = obj->vertices[(vertexIndex2 - 1) * 3 + 0];
                trucs[i * 3 + 4] = obj->vertices[(vertexIndex2 - 1) * 3 + 1];
                trucs[i * 3 + 5] = obj->vertices[(vertexIndex2 - 1) * 3 + 2];
                trucs[i * 3 + 6] = obj->vertices[(vertexIndex3 - 1) * 3 + 0];
                trucs[i * 3 + 7] = obj->vertices[(vertexIndex3 - 1) * 3 + 1];
                trucs[i * 3 + 8] = obj->vertices[(vertexIndex3 - 1) * 3 + 2];

                printf("{%d %d %d} {%f %f %f}\n", vertexIndex, vertexIndex2, vertexIndex3, obj->vertices[vertexIndex - 1], obj->vertices[vertexIndex2 - 1], obj->vertices[vertexIndex2 - 1]);
                i += 3;
            }
            //glUnmapBuffer(GL_ARRAY_BUFFER);
        	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        	glEnableVertexAttribArray(0); //j'active (il est activé (c'est bien))
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glGenBuffers(1, &main_ebo);
    i = 0;
    printf("\n");
    while (i < 108)
    {
        printf("%f ", trucs[i]);
        i++;
    }
    // exit(1);
    return (vao);
}