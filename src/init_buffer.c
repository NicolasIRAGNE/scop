/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:31:43 by niragne           #+#    #+#             */
/*   Updated: 2018/03/19 12:57:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
	
GLuint init_buffer(void)
{
	GLuint vao;
	GLuint	main_vbo;


	float vertices[] =
	{
		1.0,	1.0,	1.0,	// 8	0
		-1.0f,	1.0,	1.0, 	// 5	1
		1.0,	1.0,	-1.0f,	// 4	2
		-1.0f,	1.0,	-1.0f,	// 3	3
		1.0,	-1.0f,	1.0,	// 7	4
		-1.0f,	-1.0f,	1.0,	// 6	5
		-1.0f,	-1.0f,	-1.0f,	// 1	6
		1.0,	-1.0f,	-1.0f	// 2	7
	};

	static GLuint elements[] = 
	{
		3, 2, 6, 7, 4, 2, 0,
		3, 1, 6, 5, 4, 1, 0
	};

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    	glGenBuffers(1, &main_vbo);
    	glBindBuffer(GL_ARRAY_BUFFER, main_vbo);
        	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        	glEnableVertexAttribArray(0); //j'active (il est activé (c'est bien))
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
	glGenBuffers(1, &main_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, main_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    return (vao);
}
