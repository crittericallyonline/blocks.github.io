#version 100

precision mediump float;

uniform sampler2D imageTex;
varying vec2 TexCoord;

void main()
{
    // gl_FragColor = texture2D(imageTex, TexCoord);
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}