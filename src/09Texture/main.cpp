#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h> // has to be included first!
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "helper/RootDir.h"

#include "shared/data.h"
#include "shared/functions.h"

int main(int argc, char** argv)
{
    std::cout << "Texture" << std::endl;

    GLFWwindow* window = initAndCreateWindow(true);
    glViewport(0, 0, WIDTH, HEIGHT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    GLint shaderProgram = createShaderPipeline(textureVertexShaderSource, textureFragmentShaderSource);

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeUV), cubeUV, GL_STATIC_DRAW);

    /* Position attribute */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    /* UV attribute */
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    ImageData imageData = loadImage("TCom_Pavement_StoneGreen_4K_albedo");
    GLuint texture;
    if (imageData.data)
    {
        texture = createTexture(imageData);
        stbi_image_free(imageData.data);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    glUseProgram(shaderProgram);

    glm::vec3 viewPos(0.0f, 0.0f, 3.0f);

    while (glfwWindowShouldClose(window) == 0)
    {
        glm::mat4 model = glm::mat4(1.0f), view = glm::mat4(1.0f);
        glm::mat4 projection, modelViewProjection;
        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        view = glm::translate(view, -viewPos);
        projection = glm::perspective(glm::radians(45.0f), float(WIDTH) / float(HEIGHT), 0.1f, 1000.0f);
        modelViewProjection = projection * view * model;

        // Setting uniforms
        int modelViewProjectionLoc = glGetUniformLocation(shaderProgram, "u_modelViewProjection");
        glUniformMatrix4fv(modelViewProjectionLoc, 1, GL_FALSE, glm::value_ptr(modelViewProjection));
        int imageLoc = glGetUniformLocation(shaderProgram, "u_image");
        glUniform1i(imageLoc, 0);

        // clear the window
        glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        // swap buffer
        glfwSwapBuffers(window);

        // process user events
        glfwPollEvents();
    }

    glfwTerminate();
}