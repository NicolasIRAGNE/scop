/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_settarget.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:09:40 by niragne           #+#    #+#             */
/*   Updated: 2018/02/19 14:13:12 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcam.h"

void    cam_settarget(t_cam *cam, t_vec3 target)
{
    cam->orientation = vec3_sub(target, cam->pos);
    cam->orientation = vec3_normalize(cam->orientation);
    cam->phi = asin(cam->orientation.x);
    cam->teta = acos(cam->orientation.y / cos(cam->phi));
    if (cam->orientation.y < 0)
        cam->teta *= -1;
    cam->phi = cam->phi * 180 / M_PI;
    cam->teta = cam->teta * 180 / M_PI;
}