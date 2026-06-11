// PhongLighting.cpp : Defines the entry point for the application.
//

#include <glad/glad.h>
#include <glfw/glfw3.h>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	const int width = 900;
	const int height = 900;

	GLFWwindow* win = glfwCreateWindow(width, height, "Basic Phong Lighting", nullptr, nullptr);
	glfwSetWindowPos(win, 300, 300);
	if (win == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(win);
	gladLoadGL();

	glViewport(0, 0, width, height);


	while (!glfwWindowShouldClose(win))
	{




		glfwPollEvents();
	}

	return 0;
}
