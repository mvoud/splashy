#include "time.h"

DeltaTime& DeltaTime::GetDeltaTime()
{
	this->currentFrameTime = glfwGetTime();
	this->deltaTime = currentFrameTime - lastFrameTime;
	this->lastFrameTime = currentFrameTime;
  
	return *this;
}
