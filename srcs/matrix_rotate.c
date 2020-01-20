/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:49 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:00:50 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix	matrix_rotate(float angle, t_vec vec)
{
	t_matrix mat;

	mat = matrix_new(4, 4);
	if (mat.ptr)
	{
		mat.ptr[0] = cos(angle) + vec.arr[0] * vec.arr[0]
					* (1 - cos(angle));
		mat.ptr[1] = vec.arr[0] * vec.arr[1] *
					(1 - cos(angle)) - vec.arr[2] * sin(angle);
		mat.ptr[2] = vec.arr[0] * vec.arr[2] *
					(1 - cos(angle)) + vec.arr[1] * sin(angle);
		mat.ptr[4] = vec.arr[0] * vec.arr[1] *
					(1 - cos(angle)) + vec.arr[2] * sin(angle);
		mat.ptr[5] = cos(angle) + vec.arr[1] *
					vec.arr[1] * (1 - cos(angle));
		mat.ptr[6] = vec.arr[1] * vec.arr[2] *
					(1 - cos(angle)) - vec.arr[0] * sin(angle);
		mat.ptr[8] = vec.arr[0] * vec.arr[2] *
					(1 - cos(angle)) - vec.arr[1] * sin(angle);
		mat.ptr[9] = vec.arr[1] * vec.arr[2] *
					(1 - cos(angle)) + vec.arr[0] * sin(angle);
		mat.ptr[10] = cos(angle) + vec.arr[2] * vec.arr[2] * (1 - cos(angle));
		mat.ptr[15] = 1;
	}
	return (mat);
}
