/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:39 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 19:01:15 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"
#include "libft.h"
#include <time.h>
#include "load_obj.h"

static void					indices_check(t_obj *new_obj, int num)
{
	if (num == 3)
	{
		new_obj->indices[new_obj->number_indices] =
		new_obj->number_vertices - 3;
		new_obj->indices[new_obj->number_indices + 1] =
		new_obj->number_vertices - 2;
		new_obj->indices[new_obj->number_indices + 2] =
		new_obj->number_vertices - 1;
		new_obj->number_indices += 3;
		return ;
	}
	new_obj->indices[new_obj->number_indices] =
	new_obj->number_vertices - 4;
	new_obj->indices[new_obj->number_indices + 1] =
	new_obj->number_vertices - 3;
	new_obj->indices[new_obj->number_indices + 2] =
	new_obj->number_vertices - 1;
	new_obj->indices[new_obj->number_indices + 3] =
	new_obj->number_vertices - 3;
	new_obj->indices[new_obj->number_indices + 4] =
	new_obj->number_vertices - 2;
	new_obj->indices[new_obj->number_indices + 5] =
	new_obj->number_vertices - 1;
	new_obj->number_indices += 6;
}

static void					copy_info(char *line,
int *flag, void *new_obj, t_vec *buffer)
{
	int					coord;

	(*flag)++;
	coord = ft_atoi(line) - 1;
	if (coord >= 0)
	{
		ft_memcpy(new_obj, buffer[coord].arr, 3 * sizeof(float));
	}
}

static void					fragments(char *line, t_obj *new_obj,
t_vertices_buffer *buffer, int *num)
{
	int					n;
	int					flag;

	flag = 0;
	n = -1;
	while (line[++n])
	{
		if (ft_isdigit(line[n]) && flag == 0)
			copy_info(line + n, &flag, new_obj->vertices
		[new_obj->number_vertices].position, buffer->positions);
		else if (line[n] == '/' && flag == 1)
			copy_info(line + n + 1, &flag, new_obj->vertices
		[new_obj->number_vertices].position + 6, buffer->texcoords);
		else if (line[n] == '/' && flag == 2)
			copy_info(line + n + 1, &flag, new_obj->vertices
		[new_obj->number_vertices].position + 3, buffer->normals);
		else if (line[n] == ' ')
		{
			(*num)++;
			flag = 0;
			new_obj->vertices[new_obj->number_vertices
			- 1].position[8] = (float)(rand() % 1000) / 1000;
			new_obj->number_vertices++;
		}
	}
}

static void					read_obj_file(const char *obj, t_obj *new_obj,
									int count[4], t_vertices_buffer *buffer)
{
	int					num;
	int					fd;
	char				*line;

	fd = open(obj, O_RDONLY);
	if (!(new_obj->vertices = ft_memalloc(sizeof(t_vertex) * count[3] * 6)))
		exit(-1);
	if (!(new_obj->indices = ft_memalloc(sizeof(int) * count[3] * 6)))
		exit(-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'f' && line[1] == ' ')
		{
			num = 0;
			fragments(line, new_obj, buffer, &num);
			new_obj->number_vertices++;
			indices_check(new_obj, num);
		}
	}
	close(fd);
}

t_obj						*load_obj(const char *obj)
{
	int					count[4];
	t_obj				*new_obj;
	t_vertices_buffer	*buffer;

	if (!(new_obj = ft_memalloc(sizeof(t_obj))))
		exit(-1);
	counting_elements(obj, count);
	buffer = read_parametrs_obj(obj, count[0], count[2], count[1]);
	read_obj_file(obj, new_obj, count, buffer);
	return (new_obj);
}
