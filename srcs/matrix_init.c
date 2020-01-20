/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:43 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:03:19 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix	matrix_new(int heigth, int width)
{
	t_matrix mat;

	if (heigth != 0 && width != 0)
	{
		mat.heigth = heigth;
		mat.width = width;
		mat.ptr = ft_memalloc(sizeof(float) * heigth * width);
	}
	else
	{
		mat.heigth = 0;
		mat.width = 0;
		mat.ptr = 0;
	}
	return (mat);
}

t_matrix	matrix_identity(int size)
{
	t_matrix	matrix;
	int			i;

	matrix = matrix_new(size, size);
	if (matrix.ptr)
	{
		i = 0;
		while (i < size)
		{
			matrix.ptr[i + i * size] = 1;
			i++;
		}
	}
	return (matrix);
}

t_vec		new_vec3(float x, float y, float z)
{
	t_vec vec;

	vec.vec.x = x;
	vec.vec.y = y;
	vec.vec.z = z;
	return (vec);
}
