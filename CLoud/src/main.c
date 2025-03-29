#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <malloc.h>

#include <gx/matrix.h>

char* vertexShader = "#version 460 core\n"
"layout(location=0) in vec3 vertexPosition;\n"
"void main() {\n"
"    gl_Position.xyz = vertexPosition;\n"
"    gl_Position.w = 1.0;\n"
"}";

char* fragmentShader = "#version 460 core\n"
"out vec3 color;\n"
"void main() { \n"
"    color = vec3(0.2, 0.7, 0.4); \n"
" }";

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 0);

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    const float triangle[9] = {
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    int InfoLogLength;
    glShaderSource(vertexShaderID, 1, &vertexShader, NULL);
    glCompileShader(vertexShaderID);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    char* vertexShaderERROR = malloc((InfoLogLength + 1) * sizeof(char));
    glGetShaderInfoLog(vertexShaderID, InfoLogLength, NULL, &vertexShaderERROR[0]);
    fprintf(stdout, "vertexShader message\n%s", &vertexShaderERROR[0]);
    free(vertexShaderERROR);

    glShaderSource(fragmentShaderID, 1, &fragmentShader, NULL);
    glCompileShader(fragmentShaderID);
    glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    char* fragmentShaderERROR = malloc((InfoLogLength + 1) * sizeof(char));
    glGetShaderInfoLog(vertexShaderID, InfoLogLength, NULL, &fragmentShaderERROR[0]);
    fprintf(stdout, "fragmentShader message\n%s", &fragmentShaderERROR[0]);
    free(fragmentShaderERROR);

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    glClearColor(0, 0, 0.4, 0);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(programID);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}