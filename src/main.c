/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:17:01 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 14:32:16 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

GLuint	main_vbo;

int    main()
{
    SDL_Window	*win;
	SDL_Event	event;
	GLuint		vao;
	GLuint		prog;
	t_mat4		projection;
	t_mat4		modelview;
	t_mat4		look;
	Uint8		*key;
	Uint32		t1;
	Uint32		fps;
	Uint32		frame = 0;
	GLuint		id_texture;
	GLenum		format;
	GLenum		format2;

	// Camera
	t_cam camera;

	camera.pos = (t_vec3){2, 2, 2};
	camera.target = (t_vec3){0.0, 0.0, 0.0};
	camera.vertical = (t_vec3){0.0, 1.0, 0.0};
	camera.phi = 0.f;
	camera.teta = 0.f;

	int 		done = 0;
	float		souri[2] = {0, 0};

	if (!(win = init_sdl()))
		return (0);
	vao = init_buffer();
	projection = mat4_perspective(M_PI_2, ((float)WIN_X / (float)WIN_Y), 1.f, 100.f);
	modelview = mat4_id_new();
	prog = create_prog("shader/truc.vert", "shader/truc.frag");
	look = mat4_id_new();
	key = (Uint8 *)SDL_GetKeyboardState(NULL);
	SDL_Surface *texture = IMG_Load("./truc.jpg");
	glGenTextures(1, &id_texture);
	glBindTexture(GL_TEXTURE_2D, id_texture);
	cam_settarget(&camera, camera.target);
	if(texture->format->BytesPerPixel == 3)
	{
		format = GL_RGB;
		if(texture->format->Rmask == 0xff)
    		format2 = GL_RGB;
    	else
    		format2 = GL_BGR;
	}
	else if(texture->format->BytesPerPixel == 4)
	{    
		format = GL_RGBA;
		if(texture->format->Rmask == 0xff)
			format2 = GL_RGBA;
    	else
    		format2 = GL_BGRA;
	}
	if (!texture)
	{
		printf("%s\n", SDL_GetError());
		exit(1);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, format, texture->w, texture->h, 0, format2, GL_UNSIGNED_BYTE, texture->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);
	while (!done)
	{
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				done = 1;
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					done = 1;
			}
			
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
					souri[0] = 0;
				else if (event.button.button == SDL_BUTTON_RIGHT)
					souri[1] = 0;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
					souri[0] = 1;
				else if (event.button.button == SDL_BUTTON_RIGHT)
					souri[1] = 1;
			}
			else if (event.type == SDL_MOUSEMOTION)
			{
				cam_orient(&camera, event.motion.xrel, event.motion.yrel, 0.5);	
			}
		}
		if (key[SDL_SCANCODE_W])
			cam_move_up(&camera, 0.1);
		if (key[SDL_SCANCODE_A])
			cam_move_left(&camera, 0.1);
		if (key[SDL_SCANCODE_S])
			cam_move_down(&camera, 0.1);
		if (key[SDL_SCANCODE_D])
			cam_move_right(&camera, 0.1);
		if (key[SDL_SCANCODE_Q])
			mat4_rotate(&modelview, vec3_normalize((t_vec3){0.f, 0.f, 1.f}), M_PI / 64.f);
		if (key[SDL_SCANCODE_E])
			mat4_rotate(&modelview, vec3_normalize((t_vec3){0.f, 0.f, -1.f}), M_PI / 64.f);
		if (key[SDL_SCANCODE_I])
			modelview = mat4_vec3_mult(modelview, ((t_vec3){1.01, 1.01, 1.01}));
		if (key[SDL_SCANCODE_O])
			modelview = mat4_vec3_mult(modelview, ((t_vec3){0.99, 0.99, 0.99}));
		if (key[SDL_SCANCODE_RIGHT])
			mat4_translate(&projection, (t_vec3){-0.03f, 0.f, 0.f});
		if (key[SDL_SCANCODE_LEFT])
			mat4_translate(&projection, (t_vec3){0.03f, 0.f, 0.f});;
		if (key[SDL_SCANCODE_UP])
			mat4_translate(&projection, (t_vec3){0.f, 0.f, 0.03f});;
		if (key[SDL_SCANCODE_DOWN])
			mat4_translate(&projection, (t_vec3){0.f, 0.f, -0.03f});
			
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		look = cam_lookat(&camera);
		//free(modelview);
		//modelview = mat4_id_new();
		printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n",  look[0], look[1], look[2], look[3], look[4], look[5], look[6], look[7], look[8], look[9], look[10], look[11], look[12], look[13], look[14], look[15]);
		//exit(1);
		glUseProgram(prog);
			glBindVertexArray(vao);
				glUniformMatrix4fv(glGetUniformLocation(prog, "projection"), 1, GL_FALSE, projection);
				glUniformMatrix4fv(glGetUniformLocation(prog, "modelview"), 1, GL_FALSE, modelview);
				glUniformMatrix4fv(glGetUniformLocation(prog, "look"), 1, GL_FALSE, look);
				glBindTexture(GL_TEXTURE_2D, id_texture);
					glDrawArrays(GL_TRIANGLES, 0, 36);
				glBindTexture(GL_TEXTURE_2D, 0);
			glBindVertexArray(0);
		glUseProgram(0);
		SDL_GL_SwapWindow(win);
		t1 = SDL_GetTicks();
        if (t1 - fps >= 1000)
		{
			printf("%d\n", frame);
			fps = t1;
			frame = 0;
		}
		frame++;
	}
    return (0);
}