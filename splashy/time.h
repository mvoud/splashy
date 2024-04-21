#pragma once
#include "stdafx.h"

class DeltaTime {
public:
	DeltaTime& GetDeltaTime();
	double lastFrameTime;
	double deltaTime;
	double currentFrameTime;
};