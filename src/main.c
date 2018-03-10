/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:17:01 by niragne           #+#    #+#             */
/*   Updated: 2018/03/10 18:37:39 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

GLuint	skybox_vbo;
GLuint	main_ebo;

# define SPEED 64.f

int    main(int ac, char **av)
{
    SDL_Window	*win;
	SDL_Event	event;
	GLuint		vao;
	GLuint		vao_skybox;
	GLuint		prog;
	GLuint		prog_cursor;
	GLuint		prog_skybox;
	t_mat4		projection;
	t_mat4		modelview;
	t_mat4		translate;
	t_mat4		look;
	Uint8		*key;
	Uint32		t1;
	Uint32		fps;
	Uint32		frame = 0;
	GLuint		id_texture;
	GLenum		format;
	GLenum		format2;
	float		speed;
	t_bmp	*skybox_texture[6];
	GLuint		skybox_texture_id;
	GLuint		skybox_location;

	// Camera
	t_cam camera;

	camera.pos = (t_vec3){3.0, 3.0, 3.0};
	camera.target = (t_vec3){0.0, 0.0, 0.0};
	camera.vertical = (t_vec3){0.0, 2.0, 0.0};
	camera.phi = -90.f;
	camera.teta = -135.f;

	int 		done = 0;
	float		souri[2] = {0, 0};

	if (ac != 2)
		return (0);
	if (!(win = init_sdl()))
		return (0);
	vao = init_buffer();
	vao_skybox = init_skybox_buffer();
//	projection = mat4_id_new();
//	projection[0] = (float)WIN_Y / (float)WIN_X;
//	projection[10] = 0.1f;
	translate = mat4_id_new();
	projection = mat4_perspective((70.f / 360.f * 2.f * M_PI), ((float)WIN_X / (float)WIN_Y), 0.1f, 200.f);
	//projection = mat4_vec3_mult(projection, ((t_vec3){1, 1, -1.00}));
	modelview = mat4_id_new();
	prog = create_prog("shader/truc.vert", "shader/truc.frag");
	if (prog == UINT_MAX)
		exit(printf("failed to create prog\n"));
	prog_cursor = create_prog("shader/cursor.vert", "shader/cursor.frag");
	if (prog_cursor == UINT_MAX)
		exit(printf("failed to create prog_cursor\n"));
	prog_skybox = create_prog("shader/skybox.vert", "shader/skybox.frag");
	if (prog_skybox == UINT_MAX)
		exit(printf("failed to create prog_skybox\n"));
	look = mat4_id_new();
	key = (Uint8 *)SDL_GetKeyboardState(NULL);
	SDL_Surface *texture = IMG_Load(av[1]);
	glGenTextures(1, &id_texture);
	glBindTexture(GL_TEXTURE_2D, id_texture);
		cam_settarget(&camera, camera.target);
		if (texture->format->BytesPerPixel == 3)
		{
			format = GL_RGB;
			if (texture->format->Rmask == 0xff)
	    		format2 = GL_RGB;
    		else
    			format2 = GL_BGR;
		}
		else if (texture->format->BytesPerPixel == 4)
		{    
			format = GL_RGBA;
			if (texture->format->Rmask == 0xff)
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
	skybox_texture[0] = load_bmp("skybox/XP.bmp");
	skybox_texture[1] = load_bmp("skybox/XN.bmp");
	skybox_texture[2] = load_bmp("skybox/YP.bmp");
	skybox_texture[3] = load_bmp("skybox/YN.bmp");
	skybox_texture[4] = load_bmp("skybox/ZP.bmp");
	skybox_texture[5] = load_bmp("skybox/ZN.bmp");
	if (!skybox_texture[0] || !skybox_texture[1] || !skybox_texture[2] || !skybox_texture[3] || !skybox_texture[4] || !skybox_texture[5])
		exit(1);
	glEnable(GL_TEXTURE_CUBE_MAP);
	glGenTextures(1, &skybox_texture_id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skybox_texture_id);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	int i = 0;
	while (i < 6)
	{
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, skybox_texture[i]->info.w, skybox_texture[i]->info.h, 0, GL_RGB, GL_UNSIGNED_BYTE, skybox_texture[i]->pixels);
		i++;
	}
	skybox_location = glGetUniformLocation(prog_skybox, "cubeMap");
	glUniform1i(skybox_location, 0);
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

			translate[12] = camera.pos.x;
			translate[13] = camera.pos.y;
			translate[14] = camera.pos.z;
		if (key[SDL_SCANCODE_W])
		{
			cam_move_up(&camera, speed);
		}
		if (key[SDL_SCANCODE_A])
		{
			cam_move_left(&camera, speed);
		}
		if (key[SDL_SCANCODE_S])
		{
			cam_move_down(&camera, speed);
		}
		if (key[SDL_SCANCODE_D])
		{
			cam_move_right(&camera, speed);
		}
		if (key[SDL_SCANCODE_LSHIFT])
			speed = 0.2;
		else
			speed = 0.1;
			
		//SDL_WarpMouseInWindow(win, WIN_X / 2, WIN_Y / 2);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		look = cam_lookat(&camera);
		//free(modelview);
		//modelview = mat4_id_new();
//		printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n",  look[0], look[1], look[2], look[3], look[4], look[5], look[6], look[7], look[8], look[9], look[10], look[11], look[12], look[13], look[14], look[15]);
		//exit(1);
		glUseProgram(prog);
			glBindVertexArray(vao);
				glUniformMatrix4fv(glGetUniformLocation(prog, "projection"), 1, GL_FALSE, projection);
				glUniformMatrix4fv(glGetUniformLocation(prog, "modelview"), 1, GL_FALSE, modelview);
				glUniformMatrix4fv(glGetUniformLocation(prog, "translate"), 1, GL_FALSE, translate);
				glUniformMatrix4fv(glGetUniformLocation(prog, "look"), 1, GL_FALSE, look);
				glBindTexture(GL_TEXTURE_CUBE_MAP, skybox_texture_id);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, main_ebo);
						glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_INT, (GLvoid*)0);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
					//glDrawArrays(GL_TRIANGLES, 0, 72);
				glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glBindVertexArray(0);
		glUseProgram(prog_cursor);
			glDrawArrays(GL_POINTS, 0, 3);
		glUseProgram(prog_skybox);
			glBindVertexArray(vao_skybox);
				glUniformMatrix4fv(glGetUniformLocation(prog_skybox, "projection"), 1, GL_FALSE, projection);
				glUniformMatrix4fv(glGetUniformLocation(prog_skybox, "modelview"), 1, GL_FALSE, modelview);
				glUniformMatrix4fv(glGetUniformLocation(prog_skybox, "translate"), 1, GL_FALSE, translate);
				glUniformMatrix4fv(glGetUniformLocation(prog_skybox, "look"), 1, GL_FALSE, look);
				glBindTexture(GL_TEXTURE_CUBE_MAP, skybox_texture_id);
					glDrawArrays(GL_TRIANGLES, 0, 36);
				glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glBindVertexArray(0);
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