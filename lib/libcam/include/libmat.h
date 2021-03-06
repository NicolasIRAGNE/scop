/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:45:48 by niragne           #+#    #+#             */
/*   Updated: 2018/02/19 17:54:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H
# include <stdlib.h>
# include <strings.h>
# include "libft.h"

typedef float* t_mat3;
typedef float* t_mat4;

typedef struct s_vec3 t_vec3;

struct  s_vec3
{
    float x;
    float y;
    float z;
};

t_mat4      mat3_new(void);
t_mat4      mat4_new(void);
t_mat3      mat3_mult(t_mat3 a, t_mat3 b);
t_mat4      mat4_mult(t_mat4 a, t_mat4 b);
t_mat3      mat3_id_new(void);
t_mat3      mat4_id_new(void);
void        mat4_rotate(t_mat4 *mat, t_vec3 v, float angle);
t_vec3      vec3_normalize(t_vec3 v);
t_mat4      mat4_vec3_mult(t_mat4 m, t_vec3 v);
void        mat4_translate(t_mat4 *m, t_vec3 v);
t_vec3      vec3_add(t_vec3 u, t_vec3 v);
t_vec3      vec3_sub(t_vec3 u, t_vec3 v);
t_vec3      vec3_cross(t_vec3 u, t_vec3 v);
float   	vec3_dot(t_vec3 u, t_vec3 v);

#endif