#include <GLES3/gl3.h>
#ifndef TEXTURES_H
#define TEXTURES_H

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// some of it is from: https://open.gl/textures
GLuint generate_checker()
{
    GLuint image;
    // glActiveTexture(GL_TEXTURE0); // idk what this does so lets disable it and see what happens

    glGenTextures(1, &image);
    glBindTexture(GL_TEXTURE_2D, image);
    // Black/white checkerboard
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f
    };

    // now for binding data to the buffer
    // I HATE SAMPLING, pixel art ftw

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    return image;
}

GLuint load_image(const char *imagePath)
{
    GLuint image;
    glGenTextures(1, &image);
    glBindTexture(GL_TEXTURE_2D, image);
    int w, h, c;

    unsigned char *imageData = stbi_load(imagePath, &w, &h, &c, STBI_rgb_alpha);
    if(!imageData)
    {
        glDeleteTextures(1, &image);
        return 0;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if(c == 3)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    else if(c == 4)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
    
    free(imageData);

    glBindTexture(GL_TEXTURE_2D, 0);
    
    return image;
}


struct Textures {
    GLuint index[5];
} Textures;

void init_textures()
{
    Textures.index[0] = load_image("/tex/stone.png");
    // Textures.index[1] = load_image("/tex/dirt.png");
    // Textures.index[2] = load_image("/tex/grass.png");
    Textures.index[3] = load_image("/tex/oak_planks.png");
    Textures.index[4] = generate_checker();
}

#endif//PROGRAM_H
