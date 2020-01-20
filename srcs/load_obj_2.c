/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:56:49 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 19:02:33 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"
#include "libft.h"
#include <time.h>

void					next_position(char *line, t_vertices_buffer *buffer)
{
	int					n;
	int					flag;
	int					coord;

	n = 0;
	flag = 0;
	coord = 0;
	while (line[n])
	{
		if ((ft_isdigit(line[n]) || line[n] == '-') && flag == 0)
		{
			flag = 1;
			buffer->positions[buffer->number_positions].arr[coord] =
			ft_atof(line + n);
			coord++;
		}
		if (line[n] == ' ')
			flag = 0;
		n++;
	}
	buffer->number_positions++;
}

void					next_texcoord(char *line, t_vertices_buffer *buffer)
{
	int					n;
	int					flag;
	int					coord;

	n = 0;
	flag = 0;
	coord = 0;
	while (line[n])
	{
		if ((ft_isdigit(line[n]) || line[n] == '-') && flag == 0)
		{
			flag = 1;
			buffer->texcoords[buffer->number_texcoords].arr[coord] =
			ft_atof(line + n);
			coord++;
		}
		if (line[n] == ' ')
			flag = 0;
		n++;
	}
	buffer->number_texcoords++;
}

void					next_normal(char *line, t_vertices_buffer *buffer)
{
	int					n;
	int					flag;
	int					coord;

	n = 0;
	flag = 0;
	coord = 0;
	while (line[n])
	{
		if ((ft_isdigit(line[n]) || line[n] == '-') && flag == 0)
		{
			flag = 1;
			buffer->normals[buffer->number_normals].arr[coord] =
			ft_atof(line + n);
			coord++;
		}
		if (line[n] == ' ')
			flag = 0;
		n++;
	}
	buffer->number_normals++;
}

t_vertices_buffer		*read_parametrs_obj(const char *obj,
											int number_positions,
						int number_normals, int number_texcoords)
{
	t_vertices_buffer	*buffer;
	int					fd;
	char				*line;

	if (!(buffer = (t_vertices_buffer*)ft_memalloc(sizeof(t_vertices_buffer))))
		exit(-1);
	fd = open(obj, O_RDONLY);
	if (!(buffer->positions = (t_vec*)ft_memalloc(sizeof(t_vec)
	* number_positions)))
		exit(-1);
	if (!(buffer->normals = (t_vec*)ft_memalloc(sizeof(t_vec)
	* number_normals)))
		exit(-1);
	if (!(buffer->texcoords = (t_vec*)ft_memalloc(sizeof(t_vec)
	* number_texcoords)))
		exit(-1);
	while (get_next_line(fd, &line) > 0)
		if (line[0] == 'v' && line[1] == ' ')
			next_position(line, buffer);
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
			next_normal(line, buffer);
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
			next_texcoord(line, buffer);
	close(fd);
	return (buffer);
}
