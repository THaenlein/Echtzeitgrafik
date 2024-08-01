#pragma once

#include <GL/glew.h>

static const GLuint WIDTH = 1024, HEIGHT = 1024;
static const GLuint INFOLOG_LEN = 512;

struct ImageData
{
    unsigned char* data;
    int width, height, nrChannels;
};

GLfloat triangle[] = 
{
    // Position           Color   
     0.9f, -0.9f, 0.0f,   1.0f, 0.0f, 0.0f,
    -0.9f, -0.9f, 0.0f,   0.0f, 1.0f, 0.0f,
     0.0f,  0.9f, 0.0f,   0.0f, 0.0f, 1.0f
};

float rectangle[] = 
{
    // first triangle
     0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // top right
     0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // bottom right
    -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // top left 
    // second triangle
     0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // top left
};

float cube[] = {
    // Position           Color
    // Back face
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,

    // Front face
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,

    // Left face
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,

    // Right face
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,

     // Bottom face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,

    // Top face
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
};

float cubePhong[] = {
    // Position           Normal
    // Back face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,

    // Front face
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,

    // Left face
    -0.5f,  0.5f,  0.5f,  -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  -1.0f, 0.0f, 0.0f,

    // Right face
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,

     // Bottom face
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f,

    // Top face
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
};

float cubeUV[] = {
    // Position          UV Coordinates
    // Back face
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

    // Front face
    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,

    // Left face
    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,

    // Right face
     0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 0.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f, 0.0f, 0.0f,

     // Bottom face
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

     // Top face
    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f,
};


float rectangleIndexed[] = 
{
    // Position          Color
     0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // top right
     0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // top left 
};
unsigned int indices[] = 
{  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};


/* vertex data is passed as input to this shader
 * ourColor is passed as input to the to the fragment shader. */
static const GLchar* simpleVertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 ourColor;\n"
"void main() {\n"
"    gl_Position = vec4(position, 1.0f);\n"
"    ourColor = color;\n"
"}\0";

static const GLchar* simpleFragmentShaderSource =
"#version 330 core\n"
"in vec3 ourColor;\n"
"out vec4 color;\n"
"void main() {\n"
"    color = vec4(ourColor, 1.0f);\n"
"}\0";

static const GLchar* perspectiveVertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"out vec3 ourColor;\n"
"\n"
"void main()\n"
"{\n"
"    gl_Position = projection * view * model * vec4(position, 1.0);\n"
"    ourColor = color;\n"
"}\0";

static const GLchar* perspectiveFragmentShaderSource =
"#version 330 core\n"
"in vec3 ourColor;\n"
"out vec4 color;\n"
"void main() {\n"
"    color = vec4(ourColor, 1.0f);\n"
"    //color = vec4(vec3(gl_FragCoord.z), 1.0);\n"
"}\0";

static const GLchar* phongVertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 in_position;\n"
"layout (location = 1) in vec3 in_normal;\n"
"uniform mat4 u_model;\n"
"uniform mat4 u_view;\n"
"uniform mat4 u_projection;\n"
"out vec3 normal;\n"
"out vec3 fragPos;\n"
"void main() {\n"
"    gl_Position = u_projection * u_view * u_model * vec4(in_position, 1.0);\n"
"    normal = mat3(transpose(inverse(u_model))) * in_normal;\n"
"    fragPos = vec3(u_model * vec4(in_position, 1.0));\n"
"}\0";

static const GLchar* phongFragmentShaderSource =
"#version 330 core\n"
"in vec3 normal;\n"
"in vec3 fragPos;\n"
"uniform vec3 u_viewPos;\n"
"uniform vec3 u_lightPos;\n"
"layout (location = 0) out vec4 out_color;\n"
"void main() {\n"
"	float ambientStr = 0.1;\n"
"	vec3 lightColor = vec3(1.0, 1.0, 1.0);\n"
"	vec3 ambient = ambientStr * lightColor;\n"
"\n"
"	vec3 norm = normalize(normal);\n"
"	vec3 lightDir = normalize(u_lightPos - fragPos);\n"
"	vec3 diffuse = max(dot(norm, lightDir), 0.0) * lightColor;\n"
"	\n"
"	float specularStr = 0.3;\n"
"	vec3 viewDir = normalize(u_viewPos - fragPos);\n"
"	vec3 reflectDir = reflect(-lightDir, norm);\n"
"	vec3 spec = specularStr * pow(max(dot(viewDir, reflectDir), 0.0), 32) * lightColor;\n"
"\n"
"	vec3 phong = (ambient + diffuse + spec);\n"
"	out_color = vec4(phong, 1.0);\n"
"}\0";

static const GLchar* textureVertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec2 uv;\n"
"uniform mat4 u_modelViewProjection;\n"
"out vec2 texCoord;\n"
"\n"
"void main()\n"
"{\n"
"    gl_Position = u_modelViewProjection * vec4(position, 1.0);\n"
"    texCoord = uv;\n"
"}\0";

static const GLchar* textureFragmentShaderSource =
"#version 330 core\n"
"in vec2 texCoord;\n"
"uniform sampler2D u_image;\n"
"layout (location = 0) out vec4 out_color;\n"
"\n"
"void main() {\n"
"	out_color = texture(u_image, texCoord);\n"
"}\0";