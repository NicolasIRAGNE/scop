/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_orient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:19:43 by niragne           #+#    #+#             */
/*   Updated: 2018/02/19 14:39:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcam.h"

void    cam_orient(t_cam *cam, int xrel, int yrel, float mult)
{
    float tmp_phi;
    float tmp_teta;
    
    cam->teta += -xrel * mult;
    cam->phi += -yrel * mult;
    if (cam->phi > 89.0)
        cam->phi = 89.0;
    else if (cam->phi < -89.0)
        cam->phi = -89.0;
    tmp_phi = cam->phi * M_PI / 180.0;
    tmp_teta = cam->teta * M_PI / 180.0;
    cam->orientation.x = cos(tmp_phi) * sin(tmp_teta);
    cam->orientation.y = sin(tmp_phi);
    cam->orientation.z = cos(tmp_phi) * cos(tmp_teta);
    cam->lateral = vec3_cross(cam->vertical, cam->orientation);
    cam->lateral = vec3_normalize(cam->lateral);
    cam->target = vec3_add(cam->pos, cam->orientation);
}
