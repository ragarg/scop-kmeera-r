#version 410 core
layout (location = 1) in vec3 normal;
layout (location = 3) in float color1;
layout (location = 0) in vec3 position;

out vec4 normal_vertex;
out vec4 FragPos;
out vec4 Fragcolor; 

uniform mat4 mat;
uniform mat4 model;


void main()
{
	gl_Position = mat * vec4(position, 1.0f);
	FragPos = vec4(position, 1.0f);
	Fragcolor = vec4(color1, color1, color1, 1.0f);
	normal_vertex = model * vec4(normal, 0.0f);
}