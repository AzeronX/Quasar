#pragma once


// Include Windows

#ifdef _WIN32
#include <GL/glew.h>


// Include Mac

#elif __APPLE__
#define GL3_PROTOTYPES 1
#include <OpenGL/gl3.h>


// Include UNIX/Linux

#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>

#endif


// Includes communs

#define GLFW_DLL
#include <GLFW/glfw3.h>

#define GLM_SWIZZLE
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtx/transform.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace glm;


