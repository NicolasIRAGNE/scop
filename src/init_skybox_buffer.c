/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skybox_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:11:15 by niragne           #+#    #+#             */
/*   Updated: 2018/03/07 14:59:48 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

GLuint	init_skybox_buffer(void)
{
    GLuint vao;
    
	float vertices[] =
	{
        -100.f,-100.f,-100.f, // triangle 1 : begin
        -100.f,-100.f, 100.f,
        -100.f, 100.f, 100.f, // triangle 1 : end
        100.f, 100.f,-100.f, // triangle 2 : begin
        -100.f,-100.f,-100.f,
        -100.f, 100.f,-100.f, // triangle 2 : end
        100.f,-100.f, 100.f,
        -100.f,-100.f,-100.f,
        100.f,-100.f,-100.f,
        100.f, 100.f,-100.f,
        100.f,-100.f,-100.f,
        -100.f,-100.f,-100.f,
        -100.f,-100.f,-100.f,
        -100.f, 100.f, 100.f,
        -100.f, 100.f,-100.f,
        100.f,-100.f, 100.f,
        -100.f,-100.f, 100.f,
        -100.f,-100.f,-100.f,
        -100.f, 100.f, 100.f,
        -100.f,-100.f, 100.f,
        100.f,-100.f, 100.f,
        100.f, 100.f, 100.f,
        100.f,-100.f,-100.f,
        100.f, 100.f,-100.f,
        100.f,-100.f,-100.f,
        100.f, 100.f, 100.f,
        100.f,-100.f, 100.f,
        100.f, 100.f, 100.f,
        100.f, 100.f,-100.f,
        -100.f, 100.f,-100.f,
        100.f, 100.f, 100.f,
        -100.f, 100.f,-100.f,
        -100.f, 100.f, 100.f,
        100.f, 100.f, 100.f,
        -100.f, 100.f, 100.f,
        100.f,-100.f, 100.f
    };

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    	glGenBuffers(1, &skybox_vbo);
    	glBindBuffer(GL_ARRAY_BUFFER, skybox_vbo);
        	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), NULL, GL_STATIC_DRAW);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        	glEnableVertexAttribArray(0); //j'active (il est activé (c'est bien))     
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return (vao);
}