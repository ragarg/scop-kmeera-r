/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:47 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:02:38 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix	matrix_perspective(float fov, float aspect, float znear, float zfar)
{
	t_matrix mat;

	mat = matrix_new(4, 4);
	if (mat.ptr)
	{
		mat.ptr[0] = 1 / (tan(fov / 2) * aspect);
		mat.ptr[1 + 4] = 1 / (tan(fov / 2));
		mat.ptr[2 + 8] = (znear + zfar) / (zfar - znear);
		mat.ptr[3 + 8] = 1;
		mat.ptr[2 + 12] = (-2 * znear * zfar) / (zfar - znear);
		mat.ptr[15] = 1;
	}
	return (mat);
}
