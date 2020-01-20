/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:56 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:10:49 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader.h"
#include <stdio.h>

static GLuint	check_program(GLuint shader)
{
	GLint	success;
	GLchar	infolog[512];

	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader, 512, NULL, infolog);
		return (-1);
	}
	return (0);
}

static GLuint	check_shader(GLuint shader)
{
	GLint	success;
	GLchar	infolog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infolog);
		ft_putstr(infolog);
		return (-1);
	}
	return (0);
}

static GLuint	load_shader(const GLchar *path, GLuint type)
{
	int		fd;
	char	*string;
	char	*buffer;
	char	*shader_text;
	GLuint	shader;

	fd = open(path, O_RDONLY);
	shader_text = ft_memalloc(sizeof(char));
	shader_text[0] = 0;
	while (get_next_line(fd, &string) > 0)
	{
		buffer = ft_strjoin(shader_text, string);
		free(string);
		free(shader_text);
		shader_text = ft_strjoin(buffer, "\n");
		free(buffer);
	}
	shader = glCreateShader(type);
	glShaderSource(shader, 1, (const char *const *)&shader_text, NULL);
	glCompileShader(shader);
	if (check_shader(shader))
		return (0);
	return (shader);
}

GLuint			сreate_shader(const GLchar *vertexpath,
							const GLchar *fragmentpath)
{
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint shader;

	if (!(vertex_shader = load_shader(vertexpath, GL_VERTEX_SHADER)))
	{
		ft_putstr("vertex\n");
		return (0);
	}
	if (!(fragment_shader = load_shader(fragmentpath, GL_FRAGMENT_SHADER)))
	{
		ft_putstr("fragment\n");
		glDeleteShader(vertex_shader);
		return (0);
	}
	shader = glCreateProgram();
	glAttachShader(shader, vertex_shader);
	glAttachShader(shader, fragment_shader);
	glLinkProgram(shader);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	if (check_program(shader))
		return (0);
	return (shader);
}
