#pragma once
#include <iostream>
#include <Windows.h>

#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw/glfw3.h>
#include <glfw/glfw3native.h>

#include <glew/include/GL/glew.h>
#include <gl/GL.h>


#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imnodes-0.5/imnodes.h>
#include <stb-master/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class screen {
public:
	static int GetScreenWidth() {
		return GetSystemMetrics(SM_CXSCREEN);
	}


	static int GetScreenHeight() {
		return GetSystemMetrics(SM_CYSCREEN);
	}
};

typedef char* NChar;