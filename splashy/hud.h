#pragma once
#include "stdafx.h"

class ImHud {
public:
	ImHud& titlebar_(std::string xml);
	ImHud& menubary(bool bmx, bool bm, bool bx);
	ImHud& node_editor();
	ImHud& logger();
private:
	int GetScreenWidth() {
		return GetSystemMetrics(SM_CXSCREEN);
	}


	int GetScreenHeight() {
		return GetSystemMetrics(SM_CYSCREEN);
	}

	void RenderGradientRect(float x, float y, float width, float height, ImU32 color_down, ImU32 color_up) {
		ImVec2 pos = ImVec2(x, y);
		ImVec2 size = ImVec2(width, height);
		ImDrawList* drawList = ImGui::GetBackgroundDrawList();

		drawList->AddRectFilledMultiColor(pos, ImVec2(pos.x + size.x, pos.y + size.y), color_down, color_down, color_up, color_up);
	}

};