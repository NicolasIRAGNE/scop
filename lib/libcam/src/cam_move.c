/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:42:57 by niragne           #+#    #+#             */
/*   Updated: 2018/02/22 17:27:03 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcam.h"
#include <stdio.h>

void    cam_move_up(t_cam *cam, float speed)
{
    t_vec3 tmp;

    tmp.x = cam->orientation.x * speed;
    tmp.y = cam->orientation.y * speed;
    tmp.z = cam->orientation.z * speed;
    cam->pos = vec3_add(cam->pos, tmp);
    cam->target = vec3_add(cam->pos, cam->orientation);
}

void    cam_move_down(t_cam *cam, float speed)
{
    t_vec3 tmp;

    tmp.x = cam->orientation.x * speed;
    tmp.y = cam->orientation.y * speed;
    tmp.z = cam->orientation.z * speed;
    cam->pos = vec3_sub(cam->pos, tmp);
    cam->target = vec3_add(cam->pos, cam->orientation);
}

void    cam_move_right(t_cam *cam, float speed)
{
    t_vec3 tmp;

    tmp.x = cam->lateral.x * speed;
    tmp.y = cam->lateral.y * speed;
    tmp.z = cam->lateral.z * speed;
    cam->pos = vec3_sub(cam->pos, tmp);
    cam->target = vec3_add(cam->pos, cam->orientation);
}

void    cam_move_left(t_cam *cam, float speed)
{
    t_vec3 tmp;

    tmp.x = cam->lateral.x * speed;
    tmp.y = cam->lateral.y * speed;
    tmp.z = cam->lateral.z * speed;
    cam->pos = vec3_add(cam->pos, tmp);
    cam->target = vec3_add(cam->pos, cam->orientation);
}