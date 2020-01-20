/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:45 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:00:46 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix	matrix_mul_digit(t_matrix mat, float digit)
{
	t_matrix	new_mat;
	int			i;

	if (!mat.ptr)
	{
		new_mat = matrix_new(mat.heigth, mat.width);
		if (new_mat.ptr == 0)
			return (new_mat);
		i = 0;
		while (i < new_mat.heigth * new_mat.width)
			new_mat.ptr[i] = mat.ptr[i] * digit;
		return (new_mat);
	}
	else
		return (matrix_new(0, 0));
}

static void	sum_elements(t_matrix mat2, t_matrix mat1,
						t_matrix mat, int num_elem[2])
{
	int			k;

	mat.ptr[num_elem[1] + num_elem[0] * mat2.width] = 0;
	k = -1;
	while (++k < mat1.width)
		mat.ptr[num_elem[1] + num_elem[0] * mat2.width] +=
								mat1.ptr[k + num_elem[0] * mat2.width]
								* mat2.ptr[num_elem[1] + k * mat2.width];
}

t_matrix	matrix_mul_matrix(t_matrix mat2, t_matrix mat1)
{
	t_matrix	mat;
	int			i;
	int			j;
	int			num_elem[2];

	if (mat1.ptr && mat2.ptr && mat1.width == mat2.heigth)
	{
		mat = matrix_new(mat1.heigth, mat1.width);
		if (mat.ptr == 0)
			return (mat);
		i = -1;
		while (++i < mat1.heigth)
		{
			j = -1;
			while (++j < mat2.width)
			{
				num_elem[0] = i;
				num_elem[1] = j;
				sum_elements(mat2, mat1, mat, num_elem);
			}
		}
		return (mat);
	}
	else
		return (matrix_new(0, 0));
}
