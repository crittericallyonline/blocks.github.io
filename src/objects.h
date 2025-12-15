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

Object *create_cube()
{

    GLubyte vertices[] = {
        // front
        0, 0, 1,
        1, 0, 1,
        0, 1, 1,
        1, 0, 1,
        1, 1, 1,
        0, 1, 1,

        // back
        1, 0, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0,
        1, 0, 0,
        0, 1, 0,

        // top
        1, 1, 1,
        1, 1, 0,
        0, 1, 0,
        0, 1, 0,
        0, 1, 1,
        1, 1, 1,

        // bottom
        0, 0, 0,
        1, 0, 0,
        1, 0, 1,
        1, 0, 1,
        0, 0, 1,
        0, 0, 0,

        // left
        0, 1, 1,
        0, 1, 0,
        0, 0, 0,
        0, 1, 1,
        0, 0, 0,
        0, 0, 1,

        // right
        1, 0, 1,
        1, 0, 0,
        1, 1, 0,
        1, 0, 1,
        1, 1, 0,
        1, 1, 1,
    };

    GLuint array, verticiesBuffer,indicesBuffer;
    glGenVertexArrays(1, &array);
    glBindVertexArray(array);

    // vertex
    glGenBuffers(1, &verticiesBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, verticiesBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(Program.vertex_position, 3, GL_UNSIGNED_BYTE, false, 0, NULL);
    glEnableVertexAttribArray(Program.vertex_position);

    Object *model = (Object *) malloc(sizeof(Object));

    model->VAO = array;
    model->vert_count = sizeof(vertices) / 3;
    glBindVertexArray(0);
    glDisableVertexAttribArray(Program.vertex_position);

    return model;
}

void drawModel(Object *model)
{
    glBindVertexArray(model->VAO);
    glDrawArrays(GL_TRIANGLES, 0, model->vert_count);
    glBindVertexArray(0);
}