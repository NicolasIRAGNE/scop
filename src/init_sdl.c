/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:22:25 by niragne           #+#    #+#             */
/*   Updated: 2018/03/10 18:33:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

SDL_Window  *init_sdl(void)
{
    SDL_Window *ret;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to init sdl\n");
        return (NULL);
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 3);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    if (!(ret = SDL_CreateWindow("FT_SCOP", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,WIN_X, WIN_Y, SDL_WINDOW_FULLSCREEN_DESKTOP
    | SDL_WINDOW_OPENGL)))
    {
        printf("Failed to create window\n");
        return (NULL);
    }
    if (!(SDL_GL_CreateContext(ret)))
    {
        printf("Failed to create opengl context\n");
        return (NULL);
    }
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    glEnable(GL_MULTISAMPLE);
    // SDL_GL_SetSwapInterval(0);
    return (ret);
}