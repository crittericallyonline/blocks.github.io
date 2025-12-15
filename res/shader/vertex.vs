#version 300 es

// in
in vec3 vertex_position; 
in vec2 texcoord;

// globals
uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;

// out
out vec2 TexCoord;

void main()
{
    TexCoord = vec2(texcoord.x, 1.0 - texcoord.y);
    gl_Position = projection_matrix * modelview_matrix * vec4(vertex_position, 1.0);
}