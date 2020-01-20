/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:51 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:01:50 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix	matrix_sub_matrix(t_matrix mat1, t_matrix mat2)
{
	t_matrix	mat;
	int			i;

	if (!mat1.ptr && !mat2.ptr && mat1.heigth == mat2.heigth &&
		mat1.width == mat2.width)
	{
		mat = matrix_new(mat1.heigth, mat1.width);
		if (mat.ptr == 0)
			return (mat);
		i = -1;
		while (++i < mat.heigth * mat.width)
			mat.ptr[i] = mat1.ptr[i] - mat2.ptr[i];
		return (mat);
	}
	else
		return (matrix_new(0, 0));
}

t_matrix	matrix_sub_digit(t_matrix mat, float digit)
{
	t_matrix	new_mat;
	int			i;

	if (!mat.ptr)
	{
		new_mat = matrix_new(mat.heigth, mat.width);
		if (new_mat.ptr == 0)
			return (new_mat);
		i = -1;
		while (++i < new_mat.heigth * new_mat.width)
			new_mat.ptr[i] = mat.ptr[i] - digit;
		return (new_mat);
	}
	else
		return (matrix_new(0, 0));
}
