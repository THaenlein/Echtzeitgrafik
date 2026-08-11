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
    std::cout << "Font" << std::endl;

    GLFWwindow* window = initAndCreateWindow();
    glViewport(0, 0, WIDTH, HEIGHT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLint shaderProgram = createShaderPipeline(fontVertexShaderSource, fontFragmentShaderSource);

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_STREAM_DRAW);

    /* Position attribute */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    /* UV attribute */
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // Set up glyphs
    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        std::cerr << "Error on FreeType initialization." << std::endl;
    }

    FT_Face face = loadFont("arial.ttf", ft);
    GlyphMap glyphs;
    generateFontMap(face, 48, glyphs);

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    glUseProgram(shaderProgram);
    glActiveTexture(GL_TEXTURE0);

    // Calculate matrices
    glm::mat4 projection;
    projection = glm::ortho(-(WIDTH / 2.0f), WIDTH / 2.0f, -(HEIGHT / 2.0f), HEIGHT/2.0f);

    std::string text = "Echtzeitgrafik";
    const float startX = 0.0f;
    float y = 0.0f;
    float scale = 1.0f;
    glm::vec3 fontColor(1.0f, 1.0f, 1.0f);

    while (glfwWindowShouldClose(window) == 0)
    {
        // clear the window
        glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Setting uniforms
        int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        int imageLoc = glGetUniformLocation(shaderProgram, "text");
        glUniform1i(imageLoc, 0);
        int colorLoc = glGetUniformLocation(shaderProgram, "textColor");
        glUniform3fv(colorLoc, 1, &fontColor[0]);

        // Reset x position each frame so text doesn't drift
        float x = startX;

        std::string::const_iterator c;
        for (c = text.begin(); c != text.end(); c++) 
        { 
            Glyph ch = glyphs[*c];

            float xpos = x + ch.bearing.x * scale;
            float ypos = y - (ch.size.y - ch.bearing.y) * scale;

            float w = ch.size.x * scale;
            float h = ch.size.y * scale;

            float vertices[6][4] = 
            { 
                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos,     ypos,       0.0f, 1.0f },
                { xpos + w, ypos,       1.0f, 1.0f },

                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos + w, ypos,       1.0f, 1.0f },
                { xpos + w, ypos + h,   1.0f, 0.0f } 
            };

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBindTexture(GL_TEXTURE_2D, ch.textureID);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            x += (ch.advance >> 6) * scale;
        }

        // swap buffer
        glfwSwapBuffers(window);

        // process user events
        glfwPollEvents();
    }

    glfwTerminate();
}