#ifndef SCOP_MATH_H
# define SCOP_MATH_H

# include "libft.h"
# include "math.h"

union					u_vec
{
	struct				s_vec
	{
		float		x;
		float		y;
		float		z;
		float		w;
	}					vec;
	float			arr[4];
};
typedef union u_vec	t_vec;

typedef struct	s_matrix
{
	float		*ptr;
	int			heigth;
	int			width;
}				t_matrix;

t_matrix	matrix_new(int heigth, int width);
t_matrix	matrix_sum_matrix(t_matrix mat1, t_matrix mat2);
t_matrix	matrix_sum_digit(t_matrix mat, float digit);
t_matrix	matrix_sub_matrix(t_matrix mat1, t_matrix mat2);
t_matrix	matrix_sub_digit(t_matrix mat, float digit);
t_matrix	matrix_mul_matrix(t_matrix mat1, t_matrix mat2);
t_matrix	matrix_mul_digit(t_matrix mat, float digit);
t_matrix	matrix_perspective(float fov, float aspect, float znear, float zfar);
t_matrix	matrix_translate(t_vec offset);
t_matrix	matrix_identity(int size);
t_matrix	matrix_rotate(float angle, t_vec vec_rotate);
t_vec		new_vec3(float x, float y, float z);

#endif
