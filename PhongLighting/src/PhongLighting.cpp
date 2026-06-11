// PhongLighting.cpp : Defines the entry point for the application.
//

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Model.h"

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


	Shader shader("resources/shaders/default.vert", "resources/shaders/default.frag");

	glm::vec4 lightColor(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);

	Camera cam(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	Model wood("resources/models/candle/scene.gltf");

	shader.Activate();
	glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(win))
	{
		glClearColor(0.85f, 0.85f, 0.90f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		cam.Inputs(win);
		cam.updateMatrix(45, 0.1f, 100.0f);
		wood.Draw(shader, cam);

		glfwPollEvents();
		glfwSwapBuffers(win);
	}

	return 0;;
}
