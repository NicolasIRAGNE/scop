/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:18:38 by niragne           #+#    #+#             */
/*   Updated: 2018/02/18 12:28:28 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCOP_H
# define FT_SCOP_H

# include "libft.h"
# include "libmat.h"
# include "libcam.h"
# include <limits.h>
# include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
# include <OpenGL/gl3.h>
# include <CoreFoundation/CoreFoundation.h>
# define GL3_PROTOTYPE 1

# define WIN_X 2560
# define WIN_Y 1440

extern GLuint main_vbo;

SDL_Window  *init_sdl(void);
GLuint      init_buffer(void);
GLuint		create_prog(char *vertex_shader, char *fragment_shader);
int         shader_build(GLuint *shader, GLenum type, char *file);

#endif