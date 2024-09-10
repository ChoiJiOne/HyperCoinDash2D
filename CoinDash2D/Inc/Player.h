#pragma once

#include <map>

#include "Collision2D.h"
#include "Entity2D.h"

class IApp;
class SpriteAnim2D;

class Player : public Entity2D
{
public:
	enum class Status
	{
		IDLE = 0x00,
		RUN  = 0x01,
		HURT = 0x02,
	};

public:
	Player();
	virtual ~Player();

	DISALLOW_COPY_AND_ASSIGN(Player);

	virtual void Tick(float deltaSeconds) override;
	virtual void Render() override;
	virtual void Release() override;
	
private:
	IApp* app_ = nullptr;

	Status status_ = Status::IDLE;
	std::map<Status, SpriteAnim2D*> anims_;

	Rect2D spriteBound_;
	Rect2D collisionBound_;

	GameMath::Vec2f direction_;
	float speed_ = 200.0f;

	bool bIsFlipH_ = false;
};