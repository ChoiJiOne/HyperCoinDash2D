#include "Entity/Coin.h"
#include "GL/GLManager.h"
#include "GL/SpriteAnimator2D.h"
#include "GL/TextureAtlas2D.h"
#include "Utils/Assertion.h"

Coin::Coin()
{
	textureAtlas_ = GLManager::GetRef().GetByName<TextureAtlas2D>("TextureAtlas");
	renderBound_ = Rect2D(glm::vec2(100.0f, 100.0f), glm::vec2(32.0f, 32.0f));
	collisionBound_.radius = 16.0f;
	collisionBound_.center = renderBound_.center;
	collisionBound_.center.y += -renderBound_.size.y * 0.5f + collisionBound_.radius;

	shadow_.scale = 0.5f;
	shadow_.bound = renderBound_;
	shadow_.bound.size.y *= shadow_.scale;
	shadow_.bound.center.y += (-renderBound_.size.y * 0.5f) + (-shadow_.bound.size.y * 0.5f);
	shadow_.option.blend = glm::vec3(0.0f, 0.0f, 0.0f);
	shadow_.option.factor = 1.0f;
	shadow_.option.transparent = 0.3f;
	shadow_.option.bIsFlipV = true;

	std::vector<std::string> coinClipNames =
	{
		"Coin_1",
		"Coin_2",
		"Coin_3",
		"Coin_4",
		"Coin_5",
	};
	animator_ = GLManager::GetRef().Create<SpriteAnimator2D>(textureAtlas_, coinClipNames, 0.5f, true);



	bIsInitialized_ = true;
}

Coin::~Coin()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Coin::Tick(float deltaSeconds)
{
	animator_->Update(deltaSeconds);
}

void Coin::Render()
{
	RenderManager2D::GetRef().DrawTextureAtlas(
		animator_->GetTextureAtlas(),
		animator_->GetCurrentClipName(),
		renderBound_.center,
		renderBound_.size.x,
		renderBound_.size.y,
		0.0f
	);

	RenderManager2D::GetRef().DrawTextureAtlas(
		animator_->GetTextureAtlas(),
		animator_->GetCurrentClipName(),
		shadow_.bound.center,
		shadow_.bound.size.x,
		shadow_.bound.size.y,
		0.0f,
		shadow_.option
	);

	RenderManager2D::GetRef().DrawCircleWireframe(
		collisionBound_.center,
		collisionBound_.radius,
		glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)
	);
}

void Coin::Release()
{
	CHECK(bIsInitialized_);

	if (animator_)
	{
		GLManager::GetRef().Destroy(animator_);
		animator_ = nullptr;
	}

	textureAtlas_ = nullptr;

	bIsInitialized_ = false;
}