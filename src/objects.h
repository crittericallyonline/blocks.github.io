#include <GL/gl.h>
#include <GLES3/gl3.h>
#include <stdlib.h>
#include "program.h"

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

typedef struct Object
{
    GLuint VAO;
    uint32_t vert_count;
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

    GLuint array, verticiesBuffer,indicesBuffer;
    glGenVertexArrays(1, &array);
    glBindVertexArray(array);

    glGenBuffers(1, &verticiesBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, verticiesBuffer);
    glBufferData(GL_ARRAY_BUFFER, 3, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(Program.vertex_position, 3, GL_FLOAT, false, 0, NULL);
    glEnableVertexAttribArray(Program.vertex_position);

    Object *model = (Object *) malloc(sizeof(Object));


    model->VAO = array;
    model->vert_count = 3;
    glBindVertexArray(0);
    glDisableVertexAttribArray(Program.vertex_position);

    return model;
}

void drawModel(Object *model)
{
    glBindVertexArray(model->VAO);
    glDrawArrays(GL_LINES, 0, model->vert_count);
    glBindVertexArray(0);
}