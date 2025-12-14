#ifndef PROGRAM_H
#define PROGRAM_H

struct Program {
    GLuint shaderProgram;
    
    // uniforms
    GLuint projection_matrix;
    GLuint modelview_matrix;

    // Attributes
    GLuint vertex_position;
} Program;

#endif//PROGRAM_H
