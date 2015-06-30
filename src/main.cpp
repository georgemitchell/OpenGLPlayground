#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include "image_utils.h"

// GLM Mathematics
#include "OVR_Math.h"

// Other includes
#include "Shader.h"
#include "examples.h"

#define EX_UNKNOWN 0
#define EX_SHADERS 1
#define EX_TEXTURES 2
#define EX_TRANSFORMATIONS 3
#define EX_COORDINATES 4

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

bool show_wireframes = false;
float mix_value = 0.2f;
float mix_increment = 0.05f;

// The MAIN function, from here we start the application and run the game loop
int main(int argc, char* argv[])
{
    int example;
    if(argc > 1)
    {
        if(strcmp(argv[1], "shaders") == 0)
        {
            example = EX_SHADERS;
        }
        else if(strcmp(argv[1], "textures") == 0)
        {
            example = EX_TEXTURES;
        }
        else if(strcmp(argv[1], "transformations") == 0)
        {
            example = EX_TRANSFORMATIONS;
        }
        else if(strcmp(argv[1], "coordinates") == 0)
        {
            example = EX_COORDINATES;
        }
        else
        {
            example = EX_UNKNOWN;
        }
        if(example == EX_UNKNOWN)
        {
            printf("Unkown example option: %s\n", argv[1]);
            return 1;
        }
        else
        {
            printf("Using example mode: %s [%d]\n", argv[1], example);
        }
    }
    else
    {
        printf("No example specified, defaulting to shaders.\n");
        example = EX_SHADERS;
    }

    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    int width, height;
    
    // Needed for mac 
    glfwGetFramebufferSize(window, &width, &height);
    printf("Setting frame buffer to %d x %d\n", width, height);

    glViewport(0, 0, width, height);

    switch(example)
    {
        case EX_SHADERS:
            return run_shaders(window);

        case EX_TEXTURES:
            return run_textures(window);

        case EX_TRANSFORMATIONS:
            return run_transformations(window, (GLfloat)WIDTH / (GLfloat)HEIGHT, mix_value);

        case EX_COORDINATES:
            return run_coordinate_systems(window, (GLfloat)WIDTH / (GLfloat)HEIGHT, mix_value);

        default:
            return run_shaders(window);
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if(key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        int val;
        if(show_wireframes)
        {
            val = GL_FILL;
            show_wireframes = false;
        }
        else
        {
            val = GL_LINE;
            show_wireframes = true;
        }

        glPolygonMode(GL_FRONT_AND_BACK, val);
    }
    else if(key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        if(mix_value < 1.0)
        {
            mix_value += mix_increment;
        }
    }
    else if(key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
        if(mix_value > 0.0)
        {
            mix_value -= mix_increment;
        }
    }

}