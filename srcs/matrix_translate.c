/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:54 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:00:55 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix	matrix_translate(t_vec offset)
{
	t_matrix mat;

	mat = matrix_identity(4);
	if (mat.ptr)
	{
		mat.ptr[12] = offset.vec.x;
		mat.ptr[12 + 1] = offset.vec.y;
		mat.ptr[12 + 2] = -offset.vec.z;
	}
	return (mat);
}
