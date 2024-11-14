#include "Entity/Background.h"
#include "GL/GLManager.h"
#include "GL/RenderManager2D.h"
#include "GL/Texture2D.h"
#include "GLFW/GLFWManager.h"
#include "Utils/Assertion.h"

Background::Background()
{
	glm::vec2 screenSize = glm::vec2(0.0f, 0.0f);
	GLFWManager::GetRef().GetWindowSize(screenSize.x, screenSize.y);

	textureAtlas_ = GLManager::GetRef().GetByName<TextureAtlas2D>("TextureAtlas");
	bound_ = Rect2D(glm::vec2(0.0f, 0.0f), screenSize);

	bIsInitialized_ = true;
}

Background::~Background()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Background::Tick(float deltaSeconds)
{
}

void Background::Render()
{
	RenderManager2D::GetRef().DrawTextureAtlas(textureAtlas_, "Background", bound_.center, bound_.size.x, bound_.size.y, 0.0f);
}

void Background::Release()
{
	CHECK(bIsInitialized_);

	textureAtlas_ = nullptr;

	bIsInitialized_ = false;
}