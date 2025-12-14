#include <GL/gl.h>
#include <GLES2/gl2.h>
#include <stdlib.h>
#include "program.h"

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

typedef struct Object
{
    GLuint VAB, EAB;
    uint32_t vert_count;
    float *vertices;
    uint32_t *indicies;
} Object;

Object *create_triangle()
{

    float vertices[] = {
        0, 0.5, 0,
        0.5, -0.5, 0,
        -0.5, -0.5, 0
    };

    unsigned int indices[] = {
        0, 1, 2
    };

    GLuint buffer1;
    GLuint buffer2;
    glGenBuffers(1, &buffer1);
    glGenBuffers(1, &buffer2);
    glBindBuffer(GL_ARRAY_BUFFER, buffer1);
    glBufferData(GL_ARRAY_BUFFER, 3 * 3, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3, indices, GL_STATIC_DRAW);
    Object *model = (Object *) malloc(sizeof(Object));

    model->VAB = buffer1;
    model->EAB = buffer2;

    model->vert_count = 3;
    model->vertices = vertices;
    model->indicies = indices;

    return model;
}

void drawModel(Object *model)
{
    glVertexAttribPointer(Program.vertex_position, 3, GL_FLOAT, false, 0, model->vertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}