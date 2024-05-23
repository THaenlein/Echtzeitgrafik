#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h> // has to be included first!
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "helper/RootDir.h"

#include "shared/data.h"
#include "shared/functions.h"

int main(int argc, char** argv) 
{
    std::cout << "DebugCallback" << std::endl;
	
    GLFWwindow* window = initAndCreateWindow(true);
    glViewport(0, 0, WIDTH, HEIGHT);

    GLuint vao;
    glGenVertexArrays(-1, &vao);
    glBindBuffer(GL_DRAW_BUFFER8, vao);
    glPushDebugGroup(GL_DEBUG_SOURCE_APPLICATION, 1, -1, "Group1");
    glPopDebugGroup();
    glPopDebugGroup();

    while (glfwWindowShouldClose(window) == 0)
    {
        // clear the window
        glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // swap buffer
        glfwSwapBuffers(window);

        // process user events
        glfwPollEvents();
    }

    glfwTerminate();
}