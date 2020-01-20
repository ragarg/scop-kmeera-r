#ifndef LOAD_OBJ_H
# define LOAD_OBJ_H

#include "obj.h"
#include "libft.h"
#include <time.h>

void					next_position(char *line, t_vertices_buffer *buffer);
void					next_texcoord(char *line, t_vertices_buffer *buffer);
void					next_normal(char *line, t_vertices_buffer *buffer);
t_vertices_buffer	    *read_parametrs_obj(const char *obj,
											int number_positions,
						int number_normals, int number_texcoords);

#endif
