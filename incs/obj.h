#ifndef OBJ_H
# define OBJ_H
# include "scop_math.h"

typedef struct  s_vertex
{
    float position[9];
}               t_vertex;

typedef struct  s_obj
{
    t_vertex	*vertices;
	int			number_vertices;
    int			*indices;
	int			number_indices;
	float		del_x;
	float		del_y;
}               t_obj;

typedef struct	s_vertices_buffer
{
	t_vec		*positions;
	int			number_positions;
	t_vec		*normals;
	int			number_normals;
	t_vec		*texcoords;
	int			number_texcoords;	
}				t_vertices_buffer;

float   ft_atof(const char *number);
void	counting_elements(const char *obj, int count[4]);
t_obj   *load_obj(const char* obj);

#endif
