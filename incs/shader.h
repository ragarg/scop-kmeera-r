#ifndef SHADER_H
# define SHADER_H
# include <OpenGL/gl3.h>
# define GLFW_INCLUDE_GLCOREARB
# include <GLFW/glfw3.h>
# include "libft.h"

GLuint		сreate_shader(const GLchar* vertexPath, const GLchar* fragmentPath);

#endif
