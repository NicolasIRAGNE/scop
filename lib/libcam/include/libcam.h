/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:14:21 by niragne           #+#    #+#             */
/*   Updated: 2018/02/19 17:54:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCAM_H
# define LIBCAM_H

# include "libft.h"
# include "libmat.h"
# include <math.h>

typedef struct s_cam t_cam;

struct  s_cam
{
    float	phi;
	float	teta;
	t_vec3	orientation;
	t_vec3	vertical;
	t_vec3	lateral;
	t_vec3	pos;
	t_vec3	target;
};

void    cam_orient(t_cam *cam, int xrel, int yrel, float mult);
void    cam_move_up(t_cam *cam, float speed);
void    cam_move_down(t_cam *cam, float speed);
void    cam_move_right(t_cam *cam, float speed);
void    cam_move_left(t_cam *cam, float speed);
t_mat4  cam_lookat(t_cam *cam);
void    cam_settarget(t_cam *cam, t_vec3 target);

#endif