#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define DEBUGGER printf 
#define new(value) (value*) malloc(sizeof(value)) // Implicit casting

const char* WIN_TITLE = "Sample Vulkan";
const uint32_t WIN_WIDTH = 800;
const uint32_t WIN_HEIGHT = 600;

typedef struct App {
  GLFWwindow* window;
} App;

void initWindow(App* app);
void initVulkan(void);
void eventsLoop(App* app);
void cleanerOff(App* app);

int main() {

  App* app = new(App);

	DEBUGGER("[INFO]: main funcion startup...\n");

  initWindow(app);
  initVulkan();
  eventsLoop(app);
  cleanerOff(app);
  return 0;
}

void initWindow(App* app) {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  app->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, NULL, NULL);
	DEBUGGER("[INFO]: init glfw window...\n");
}

void initVulkan(void) { return; }

void eventsLoop(App* app) {

	DEBUGGER("[INFO]: poll events running...\n");

  while (!glfwWindowShouldClose(app->window)) {
    glfwPollEvents(); // Event listener
  }
}

void cleanerOff(App* app) {
  glfwDestroyWindow(app->window);
  glfwTerminate();
	DEBUGGER("[INFO]: application destroyed...\n");
}
