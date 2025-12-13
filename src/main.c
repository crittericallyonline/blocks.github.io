#include <stdio.h>
#include <emscripten/emscripten.h>
#include <emscripten/html5_webgl.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>

double width, height;


bool onMouseMove(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
    // printf("(%d, %d)\n", mouseEvent->clientX, mouseEvent->clientY);
    return true;
}

bool RESIZE_CALLBACK(int eventType, const EmscriptenUiEvent *uiEvent, void *userData)
{
    emscripten_get_element_css_size("#canvas", &width, &height);
    glViewport(0, 0, width, height);
    return true;
}

void update()
{
    
}

void draw()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderLoop()
{
    update();
    draw();
}

int main()
{
    if(!glfwInit())
    {
        printf("Error with creating the webgl context.\n");
        return -1;
    }

    EmscriptenWebGLContextAttributes attrs;
    
    attrs.majorVersion = 3;
    attrs.minorVersion = 2;

    emscripten_webgl_init_context_attributes(&attrs);
    
    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context = emscripten_webgl_create_context("#canvas", &attrs);

    int success = emscripten_webgl_make_context_current(context);

    if(success)
    {
        printf("error setting the webgl context to current\n");
        return -1;
    }
    
    emscripten_set_mousemove_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, true, onMouseMove);
    emscripten_get_element_css_size("#canvas", &width, &height);
    printf("%f, %f\n", width, height);
    emscripten_set_resize_callback("#canvas", NULL, true, RESIZE_CALLBACK);

    emscripten_set_main_loop(renderLoop, 0, true);

    return 0;
}