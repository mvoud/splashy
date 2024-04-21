#include "hud.h"
#include "byimage.hpp"
#include "fontawesome/IconsFontAwesome6.h"

ImHud& ImHud::titlebar_(std::string xml)
{

	return *this;
}

ImHud& ImHud::menubary(bool bmx, bool bm, bool bx)
{
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 10));

	if (ImGui::BeginMainMenuBar()) {

		RenderGradientRect(0, 0, GetScreenWidth(), 20, IM_COL32(36, 36, 36, 255), IM_COL32(51, 51, 51, 255));

		if (ImGui::BeginMenu(ICON_FA_FOLDER "  File")) {


			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu(ICON_FA_PENCIL "  Setup")) {


			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu(ICON_FA_PAPERCLIP "  Project")) {


			ImGui::EndMenu();
		}

		ImGui::SetCursorPos(ImVec2(GetScreenWidth() - 36, 0));
		if (ImGui::Button(ICON_FA_X, ImVec2(33,34))) {

		}
		ImGui::SetCursorPos(ImVec2(GetScreenWidth() - 69, 0));
		if (ImGui::Button(ICON_FA_WINDOW_MAXIMIZE, ImVec2(33, 34))) {

		}
		ImGui::SetCursorPos(ImVec2(GetScreenWidth() - 102, 0));
		if (ImGui::Button(ICON_FA_WINDOW_MINIMIZE, ImVec2(33, 34))) {

		}

		ImGui::EndMainMenuBar();
	}

	return *this;
}

#define SPLASHY_NODE_START		0x9c4f
#define SPLASHY_NODE_START_ID	0x9c5f
#define SPLASHY_NODE_END		0x8c4f
#define SPLASHY_NODE_END_ID		0x9c5f

/* ===================================
/*  Struct:
/*		node->create(int nid, const char* text, ImVec2 spacing) >> []; 
/* 
/* 
* 
/* 
/* 
/* 
/*	
/*
/*
/*
/* ===================================
*/

ImHud& ImHud::node_editor()
{
	ImGui::Begin("node editor");

	imnodes::BeginNodeEditor();
	
	// Start node
	imnodes::BeginNode(1);
	imnodes::BeginNodeTitleBar();
	ImGui::Text("OnStart");
	imnodes::EndNodeTitleBar();
	imnodes::BeginOutputAttribute(2);
	ImGui::Text("Set");
	imnodes::EndOutputAttribute();
	imnodes::EndNode();

	imnodes::SetNodeGridSpacePos(1, ImVec2(100, 100));

	// End node
	imnodes::BeginNode(3);
	imnodes::BeginNodeTitleBar();
	ImGui::Text("OnEnd");
	imnodes::EndNodeTitleBar();
	imnodes::BeginOutputAttribute(4);
	ImGui::Text("Set");
	imnodes::EndInputAttribute();
	imnodes::EndNode();

	imnodes::SetNodeGridSpacePos(3, ImVec2(100, 400));

	imnodes::BeginNode(5);
	imnodes::BeginNodeTitleBar();
	ImGui::Text("Return");
	imnodes::EndNodeTitleBar();

	// Add an input attribute
	imnodes::BeginInputAttribute(6); // Unique ID for the input attribute
	ImGui::Text("Set");
	imnodes::EndInputAttribute();

	// Add an output attribute
	imnodes::BeginOutputAttribute(7); // Unique ID for the output attribute
	ImGui::Text("Output");
	imnodes::EndOutputAttribute();

	imnodes::EndNode();


	imnodes::EndNodeEditor();


	ImGui::End();

	

	
	return *this;
}

ImHud& ImHud::logger()
{
	ImGui::Begin("Logger");


	ImGui::End();
	
	return *this;
}
