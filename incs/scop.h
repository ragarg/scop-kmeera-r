#ifndef SCOP_H
# define SCOP_H
# include <OpenGL/gl3.h>
# define GLFW_INCLUDE_GLCOREARB
# include <GLFW/glfw3.h>
# include "libft.h"
# include "obj.h"

typedef struct	s_scop
{
	t_obj *obj;
    GLFWwindow* window;
    GLuint shaderProgram;
	GLfloat deltaTime;
    GLuint VBO;
	GLuint VAO;
	GLuint EBO;	
}				t_scop;

int				init_ogl();
GLFWwindow		*init_window();
void			bindmash();

#endif
