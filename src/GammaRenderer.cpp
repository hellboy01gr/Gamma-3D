/*****************************************
*              MIT License               *
*                                        *
*     Copyright (c) 2024 hellboy01gr     *
*****************************************/

// Includes
#include <iostream>
#include <GayPrinter.h>

// OpenGL related Includes
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

// Terminal color codes use with c_color() when printing on the console
#define ERROR 197
#define WARNING 214
#define INFO 69

// Window Parameters
#define WIDTH 1280
#define HEIGHT 720
#define TITLE "Gamma-3D"

int main(int argc, char *argv[]) {

  // Initialize GLFW
  if (!glfwInit()) {
    std::cout << c_color(ERROR) << "[ERROR]: GLFW could not be initialized." << c_reset << std::endl;
    return -1;
  } else std::cout << c_color(INFO) << "[INFO]: GLFW initialized." << c_reset << std::endl;

  // Create a window with OpenGL version 4.0
  glfwWindowHint(GLFW_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_VERSION_MINOR, 0);

  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
  if (!window) {
    std::cout << c_color(ERROR) << "[ERROR]: GLFW could not create a window." << c_reset << std::endl;
    glfwTerminate();
    return -1;
  } else std::cout << c_color(INFO) << "[INFO]: Window created." << c_reset << std::endl;

  // Create an OpenGL context
  glfwMakeContextCurrent(window);
  if (!glfwGetCurrentContext()) {
    std::cout << c_color(ERROR) << "[ERROR]: OpenGL context could not be created." << c_reset << std::endl;
    glfwTerminate();
    return -1;
  } else std::cout << c_color(INFO) << "[INFO]: OpenGL context created." << c_reset << std::endl;

  // Print information about the system
  // Get number of OpenGL extensions loaded
  GLint NumExtensions;
  glGetIntegerv(GL_NUM_EXTENSIONS, &NumExtensions);

  std::cout << c_color(INFO) << "[INFO] GL_RENDERER: " << glGetString(GL_RENDERER) << "." << std::endl;
  std::cout << "[INFO] GL_VENDOR: " << glGetString(GL_VENDOR) << "." << std::endl;
  std::cout << "[INFO] GL_VERSION: " << glGetString(GL_VERSION) << "." << std::endl;
  std::cout << "[INFO] GL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "." << std::endl;
  std::cout << "[INFO] GL_NUM_EXTENSIONS: " << NumExtensions << "." << c_reset << std::endl;

  // Application loop
  while(!glfwWindowShouldClose(window)) {

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();

  }

  // When applications terminates
  glfwTerminate();
  return 0;

}
