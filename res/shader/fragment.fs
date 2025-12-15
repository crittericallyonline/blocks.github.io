#version 300 es

precision mediump float;

uniform sampler2D imageTex;
in vec2 TexCoord;
in float time;

out vec4 diffuseColor;

void main()
{
    diffuseColor = texture(imageTex, TexCoord);
}