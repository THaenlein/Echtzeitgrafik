#pragma once

#include <iostream>
#include <filesystem>

#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "helper/RootDir.h"
#include "data.h"

GLFWwindow* initAndCreateWindow(bool debugContext = false)
{
    GLFWwindow* window;  // created window

    if (glfwInit() == 0)
    {
        std::cerr << "GLFW failed to initiate." << std::endl;
    }
    glfwWindowHint(GLFW_RESIZABLE, false);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, debugContext);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Echtzeitgrafik", nullptr, nullptr);

    // check if window was created successfully
    if (window == nullptr)
    {
        std::cerr << "GLFW failed to create window." << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cerr << "GLFW failed to create window." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
    {
        // initialize debug output 
        auto debugCallback = [](
            GLenum source, GLenum type, GLuint id, GLenum severity,
            GLsizei messageLength, const GLchar* message, const void* userParam)
        {
            std::cerr << "[OpenGL] " << id << ": " << message << std::endl;
        };
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(debugCallback, nullptr);
    }
    glEnable(GL_MULTISAMPLE);

    return window;
}

GLint createShaderPipeline(const char* vertexSource, const char* fragmentSource)
{
    /* Vertex shader */
    GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[INFOLOG_LEN];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, INFOLOG_LEN, NULL, infoLog);
        printf("Vertex-Shader compilation failed\n%s\n", infoLog);
    }

    /* Fragment shader */
    GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, INFOLOG_LEN, NULL, infoLog);
        printf("Fragment-Shader compilation failed\n%s\n", infoLog);
    }

    /* Link shaders */
    GLint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, INFOLOG_LEN, NULL, infoLog);
        printf("Shader linking failed\n%s\n", infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

ImageData loadImage(std::string textureName)
{
    // Create Textures
    std::filesystem::path pathToTexture(ROOT_DIR);
    pathToTexture = pathToTexture / "res" / "textures" / (textureName + ".jpg");
    std::string texturePath = pathToTexture.string();

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* imageData = stbi_load(texturePath.data(), &width, &height, &nrChannels, 0);
    if (!imageData) {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    return { imageData, width, height, nrChannels };
}

GLuint createTexture(ImageData imageData, int unit)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageData.width, imageData.height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData.data);
    //glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return texture;
}

void loadMeshFromFile(std::string fileName, std::vector<float>& vertices, std::vector<unsigned int>& indices)
{
    std::filesystem::path pathToFile(ROOT_DIR);
    pathToFile = pathToFile / "res" / fileName;

    Assimp::Importer importer;

    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you’ll
    // probably to request more postprocessing than we do in this example.
    const aiScene* scene = importer.ReadFile(pathToFile.string(),
        aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType | aiProcess_PreTransformVertices);

    // If the import failed, report it
    if (!scene) {
        std::cerr << "Importing of 3D scene failed: " << importer.GetErrorString() << std::endl;
        return;
    }
    if (!scene->HasMeshes()) return;
    
    aiMesh* mesh = scene->mMeshes[0]; // Just load the first mesh in this example
    
    for (unsigned int j = 0; j < mesh->mNumVertices; j++) {
        // Copy the vertex data into the vector "vertices"
        aiVector3D& v = mesh->mVertices[j];
        vertices.push_back(v.x);
        vertices.push_back(v.y);
        vertices.push_back(v.z);

        if (mesh->HasVertexColors(0))
        {
            // Use vertex colors if they are available
            aiColor4D& c = mesh->mColors[0][j];
            vertices.push_back(c.r);
            vertices.push_back(c.g);
            vertices.push_back(c.b);
        }
        else 
        {
            // In this case we use the position as the color attribute
            vertices.push_back(v.x);
            vertices.push_back(v.y);
            vertices.push_back(v.z);
        }
    }
    
    for (unsigned int k = 0; k < mesh->mNumFaces; k++) {
        aiFace& face = mesh->mFaces[k];
        // Copy the index values to the vector "indices" above
        // We can assume that there are only 3 indices per face
        // because we set the aiProcess_Triangulate flag during the import.
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
}