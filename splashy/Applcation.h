#pragma once
#include "stdafx.h"

#include "hud.h"
#include "time.h"

extern bool onExit_messageBox = false;

class ApplcationCore {
public:
	virtual ApplcationCore& onUpdate() = 0;
	virtual ApplcationCore& onUI() = 0;
	virtual ApplcationCore& onExit() = 0;
	virtual ApplcationCore& onFrame() = 0;
	virtual ApplcationCore& onStartUp() = 0;
};

class Applcation : public ApplcationCore {
public:

	ApplcationCore& onStartUp() override {

		int width, height, channels;
		unsigned char* cursorData = stbi_load("assest\\dir\\cursor.png", &width, &height, &channels, 0);
		if (!cursorData) {
			fprintf(stderr, "Failed to load cursor image.\n");
			glfwTerminate();
		}

		GLFWimage image;
		image.width = width;
		image.height = height;
		image.pixels = cursorData;

		int hotSpotX = width / 2;
		int hotSpotY = height / 2;

		GLFWcursor* cursor = glfwCreateCursor(&image, hotSpotX, hotSpotY);
		glfwSetCursor(glfwGetCurrentContext(), cursor);

		return *this;
	}
	ApplcationCore& onUpdate() override {

		// DeltaTime dt;
		// dt.GetDeltaTime();
		// 
		// std::c0out << "Delta update: " << dt.deltaTime << std::endl;
		// 

	    return *this;
	}
	/*
		--- only opengl renders ---
	*/
	ApplcationCore& onUI() override {

		ImHud hud;

		hud.menubary(true, true, true)
		   .node_editor()
		   .logger()
		
		;

		return *this;
	}
	/*
		--- only onexit events ---
	*/
	ApplcationCore& onExit() override {

		GLFWwindow* window = glfwGetCurrentContext();
		HWND hwnd = glfwGetWin32Window(window);
		int messageBox_onExit = 0;
		(onExit_messageBox ?  messageBox_onExit = MessageBox(hwnd, L"Are you sure to exit without saving?", L"exit", MB_YESNO) : NULL);
		switch (messageBox_onExit)
		{
		case IDYES:



			break;
		case IDNO:

			CloseWindow(GetConsoleWindow());
			imnodes::DestroyContext();
			ImGui::DestroyContext();
			ImGui_ImplGlfw_Shutdown();
			ImGui_ImplOpenGL3_Shutdown();

			break;
		default:

			break;
		}

		

		return *this;
	}
	/*
		--- opengl operations ---
	*/
	ApplcationCore& onFrame() override {



		return *this;
	}
};