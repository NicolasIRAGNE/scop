/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:57:50 by niragne           #+#    #+#             */
/*   Updated: 2018/02/19 18:34:06 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcam.h"

/*t_mat4    cam_lookat(t_cam *cam)
{
    t_vec3 forward, side, up;
    t_mat4 matrix2;

    forward.x = cam->target.x - cam->pos.x;
    forward.y = cam->target.y - cam->pos.y;
    forward.z = cam->target.z - cam->pos.z;
    forward = vec3_normalize(forward);
    side = vec3_cross(forward, cam->vertical);
    side = vec3_normalize(side);
    up = vec3_cross(side, forward);
    matrix2 = mat4_new();
    matrix2[0] = side.x;
    matrix2[1] = side.y;
    matrix2[2] = side.z;
    matrix2[3] = 0.0;
    matrix2[4] = up.x;
    matrix2[5] = up.y;
    matrix2[6] = up.z;
    matrix2[7] = 0.0;
    matrix2[8] = -forward.x;
    matrix2[9] = -forward.y;
    matrix2[10] = -forward.z;
    matrix2[11] = 0.0;
    matrix2[12] = 0.0;
    matrix2[13] = 0.0;
    matrix2[14] = 0.0;
    matrix2[15] = 1.0;
    t_vec3 tmp = (t_vec3){-cam->pos.x, -cam->pos.y, -cam->pos.z};
    mat4_translate(&matrix2, tmp);
    return (matrix2);
}*/
/*
t_mat4  cam_lookat(t_cam *cam)
{
    t_vec3 const		z = vec3_normalize(vec3_sub(cam->target, cam->pos));
	t_vec3 const		x = vec3_normalize(vec3_cross(z, cam->vertical));
	t_vec3 const		y = vec3_cross(x, z);
    t_mat4 ret;

	ret = mat4_new();
    ret[0] = x.x;
    ret[4] = x.y;
    ret[8] = x.z;
    ret[12] = -(x.x * cam->pos.x + x.y * cam->pos.y + x.z * cam->pos.z);
    ret[1] = y.x;
    ret[5] = y.y;
    ret[9] = y.z;
    ret[13] = -(y.x * cam->pos.x + y.y * cam->pos.y + y.z * cam->pos.z);
    ret[2] = z.x;
    ret[6] = z.y;
    ret[10] = z.z;
    ret[14] = -(z.x * cam->pos.x + z.y * cam->pos.y + z.z * cam->pos.z);
	ret[3] = 0.f;
    ret[7] = 0.f;
    ret[11] = 0.f;
    ret[15] = 1.f;
    return (ret);
}*/

t_mat4  cam_lookat(t_cam *cam)
{
	t_vec3	tmp;
	t_mat4	view = mat4_id_new();

	tmp = cam->vertical;
	t_vec3 fwd = vec3_normalize(vec3_sub(cam->pos, cam->target));
	t_vec3 side = vec3_normalize(vec3_cross(cam->vertical, fwd));
	tmp = vec3_cross(fwd, side);
	view[0] = side.x;
	view[1] = tmp.x;
	view[2] = fwd.x;
	view[4] = side.y;
	view[5] = tmp.y;
	view[6] = fwd.y;
	view[8] = side.z;
	view[9] = tmp.z;
	view[10] = fwd.z;
	view[12] = -vec3_dot(side, cam->pos);
	view[13] = -vec3_dot(tmp, cam->pos);
	view[14] = -vec3_dot(fwd, cam->pos);
    return (view);
}

/*t_mat4  cam_lookat(t_cam *cam, t_mat4 mat)
{
    t_vec3 f;
    t_vec3 up;
    t_vec3 s;
    t_vec3 u;
    t_mat4 ret = mat4_new();

    f = vec3_sub(cam->pos, cam->target);
    f = vec3_normalize(f);
    up = vec3_normalize(cam->vertical);
    s = vec3_cross(f, up);
    u = vec3_cross(s, f);
    ret[0] = s.x;
    ret[1] = s.y;
    ret[2] = s.z;
    ret[3] = 0.f;
    ret[4] = u.x;
    ret[5] = u.y;
    ret[6] = u.z;
    ret[7] = 0.f;
    ret[8] = -f.x;
    ret[9] = -f.y;
    ret[10] = -f.z;
    ret[11] = 0.f;
    ret[12] = 0.f;
    ret[13] = 0.f;
    ret[14] = 0.f;
    ret[15] = 1.f;
    ret = mat4_mult(ret, mat);
    mat4_translate(&ret, (t_vec3){-cam->pos.x, -cam->pos.y, -cam->pos.z});
    return (ret);
}
*/
/*
t_mat4  cam_lookat(t_cam *cam)
{
    t_vec3 f;
	t_vec3 s;
	t_vec3 t;
    t_mat4 m;

	f = vec3_sub(cam->target, cam->pos);
	f = vec3_normalize(f);

	s = vec3_cross(f, cam->vertical);
	s = vec3_normalize(s);

	t = vec3_cross(s, f);
    m = mat4_id_new();
	m[0] =  s.x;
	m[1] =  t.x;
	m[2] = -f.x;
	m[3] =   0.f;

	m[4] =  s.y;
	m[5] =  t.y;
	m[6] = -f.y;
	m[7] =   0.f;

	m[8] =  s.z;
	m[9] =  t.z;
	m[10] = -f.z;
	m[11] =   0.f;

	m[12] =  0.f;
	m[13] =  0.f;
	m[14] =  0.f;
	m[15] =  1.f;

	mat4_translate(&m, (t_vec3){-cam->pos.x, -cam->pos.y, -cam->pos.z});
    return (m);
}*/