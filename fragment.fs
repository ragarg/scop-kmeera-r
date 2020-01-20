#version 410 core
in  vec4 normal_vertex;
out vec4 color;
in vec4 FragPos;
in vec4 Fragcolor; 



void main()
{
	vec4 point = vec4(-5.0f, 2.0f, -10.0f, 1.0f);
	float			i;
	float			n_dot_l;

	i = 0.0f;
	float diff = max(dot(normalize(normal_vertex), normalize(point - FragPos)), 0.0);
	if (length(normal_vertex) != 0)
		color = vec4(vec3(Fragcolor) * diff, 1.0f);
	else
		color = vec4(Fragcolor);
}