/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:18:38 by niragne           #+#    #+#             */
/*   Updated: 2018/03/25 19:28:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCOP_H
# define FT_SCOP_H

# include "libft.h"
# include "libmat.h"
# include "libcam.h"
# include <fcntl.h>
# include <limits.h>
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include <OpenGL/gl3.h>
# include <sys/mman.h>
# include <sys/stat.h>
# define GL3_PROTOTYPE 1

# define WIN_X 2560
# define WIN_Y 1440

extern GLuint   main_vbo;
extern GLuint   skybox_vbo;
extern GLuint   main_ebo;
typedef struct s_bmp_info t_bmp_info;
typedef struct s_bmp_header t_bmp_header;
typedef struct s_bmp t_bmp;
typedef struct s_obj t_obj;
typedef int		t_int32;
typedef unsigned int		t_uint32;
typedef unsigned short int		t_uint16;

SDL_Window  *init_sdl(void);
GLuint      init_buffer(void);
GLuint      init_skybox_buffer(void);
GLuint		create_prog(char *vertex_shader, char *fragment_shader);
int         shader_build(GLuint *shader, GLenum type, char *file);
t_bmp		*load_bmp(char *name);
t_obj		*load_model(char *name);
GLuint		init_buffer_model(t_obj *obj);

struct		s_bmp_header
{
	t_uint16	empty;
	t_uint16	type;
	t_uint32	size;
	t_uint16	reserved1;
	t_uint16	reserved2;
	t_uint32	offset;
};

struct      s_bmp_info
{
	t_uint32	size;
	int				w;
	int				h;
	t_uint16 planes;
	t_uint16 bits;
	t_uint32 compression;
	t_uint32 imagesize;
	int xresolution;
	int	yresolution;
	t_uint32 ncolours;
	t_uint32 importantcolours;
};

struct	s_bmp
{
	t_bmp_header	header;
	t_bmp_info		info;
	void		*pixels;
};

struct	s_obj
{
	float	*vertices;
	size_t	nb_vertices;
	float	*coord_texture;
	size_t	nb_coords;
	float	*normal;
	size_t	nb_normal;
	int		*face;
	size_t	nb_face;
};

#endif