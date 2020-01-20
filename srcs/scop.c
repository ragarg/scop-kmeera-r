/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:58 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:04:22 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				init_ogl(void)
{
	if (!glfwInit())
	{
		return (-1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	return (0);
}

GLFWwindow		*init_window(GLint width, GLint height, GLchar *name)
{
	GLFWwindow	*window;

	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	return (window);
}
