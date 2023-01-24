#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
	if (!glfwInit())
	{
		printf("Could not initilalize GLFW");
		glfwTerminate();
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glewExperimental = GL_TRUE;

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		printf("Unable to initialize GLEW");
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	int bufferWidth, bufferHeight;
	glfwGetWindowFrameSize(window, 0, 0, &bufferWidth, &bufferHeight);

	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}