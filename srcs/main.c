/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:41 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/20 13:30:52 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shader.h"
#include "scop.h"
#include "obj.h"
#include "scop_math.h"

void create_mvp_matrix(float deltaTime, GLuint shaderProgram)
{
    t_matrix		model;
    t_matrix		view;
    t_matrix		projection;
    t_matrix		mat;
    static	float	angle = 0.0f;

    angle += deltaTime;
    model = matrix_rotate(angle, new_vec3(0.0f, 1.0f, 0.0f));
    view = matrix_translate(new_vec3(0.0f, 0.0f, -8.0f));
    projection = matrix_perspective(45.0f, (GLfloat)16
				/ (GLfloat)9, 0.1f, 100.0f);
    mat = matrix_mul_matrix(projection, view);
    mat = matrix_mul_matrix(mat,
	matrix_rotate(0.4, new_vec3(1.0f, 0.0f, 0.0f)));
    mat = matrix_mul_matrix(mat, model);
    GLint matLoc = glGetUniformLocation(shaderProgram, "mat");
    glUniformMatrix4fv(matLoc, 1, GL_FALSE, mat.ptr);
    GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.ptr);
}

void	create_buffer(GLuint *vbo, GLuint *vao, GLuint *ebo, t_obj *obj)
{
	glGenVertexArrays(1, vao);
	glGenBuffers(1, vbo);
	glGenBuffers(1, ebo);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) *
	obj->number_vertices, obj->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) *
	obj->number_indices, obj->indices, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
	9 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
	9 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
	9 * sizeof(float), (GLvoid*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE,
	9 * sizeof(float), (GLvoid*)(8 * sizeof(float)));
	glEnableVertexAttribArray(3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void	swap_buffer(float deltatime, GLuint shaderprogram,
					t_obj *obj, GLFWwindow *window)
{
	glfwPollEvents();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderprogram);
	create_mvp_matrix(deltatime, shaderprogram);
	glDrawElements(GL_TRIANGLES, obj->number_indices, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glfwSwapBuffers(window);
}

GLfloat	update_time(void)
{
	GLfloat			deltatime;
	static GLfloat	lastframe = 0.0f;
	static int		fps = 0;
	static float	time = 0;
	GLfloat			currentframe;

	currentframe = glfwGetTime();
	deltatime = currentframe - lastframe;
	if (deltatime < 0.015)
		return (-1.0f);
	if (time > 1)
	{
		ft_putnbr(fps);
		ft_putchar('\n');
		time = 0;
		fps = 0;
	}
	lastframe = currentframe;
	fps++;
	time += deltatime;
	return (deltatime);
}

int		main(void)
{
	t_scop scop;

	printf("\n");
	if (init_ogl())
		return (-1);
	if (!(scop.window = init_window(1920, 1080, "SCOP")))
		return (-1);
	if (!(scop.shaderProgram = сreate_shader("vertex.vs", "fragment.fs")))
		return (-1);
	if (!(scop.obj = load_obj("42.obj")))
		return (-1);
	create_buffer(&scop.VBO, &scop.VAO, &scop.EBO, scop.obj);
	while (!glfwWindowShouldClose(scop.window))
	{
		if ((scop.deltaTime = update_time()) < 0)
			continue ;
		glBindVertexArray(scop.VAO);
		swap_buffer(scop.deltaTime, scop.shaderProgram,
					scop.obj, scop.window);
		if (GLFW_PRESS == glfwGetKey(scop.window, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(scop.window, 1);
	}
	glDeleteVertexArrays(1, &scop.VAO);
	glDeleteBuffers(1, &scop.VBO);
	glDeleteBuffers(1, &scop.EBO);
	glfwTerminate();
	return (0);
}
