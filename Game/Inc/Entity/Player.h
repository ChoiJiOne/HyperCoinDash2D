#pragma once

#include <map>

#include "Entity/IEntity2D.h"
#include "GL/RenderManager2D.h"
#include "Physic/Circle2D.h"
#include "Physic/Rect2D.h"

/** Ŭ���� ���� �����Դϴ�. */
class SpriteAnimator2D;
class TextureAtlas2D;

/** �÷��̾ ������ ��ƼƼ�Դϴ�. */
class Player : public IEntity2D
{
public:
	Player();
	virtual ~Player();

	DISALLOW_COPY_AND_ASSIGN(Player);

	virtual void Tick(float deltaSeconds) override;
	virtual void Render() override;
	virtual void Release() override;

private:
	/** �÷��̾��� �ִϸ��̼� �����Դϴ�. */
	enum class EAnimationState
	{
		IDLE = 0x00,
		RUN  = 0x01,
		HURT = 0x02,
	};

	/** �÷��̾��� �׸����Դϴ�. */
	struct Shadow
	{
		Rect2D bound; /** �׸��� �����Դϴ�. */
		TextureDrawOption option; /** �׸��� ������ �� ������ �ɼ��Դϴ�. */
		float scale = 0.0f; /** �׸����� ������ ���Դϴ�. */
	};

	/** �÷��̾��� �ִϸ��̼� ���¸� �ʱ�ȭ�մϴ�. */
	void LoadAnimations();

	/** �÷��̾��� �ִϸ��̼� ���� �ʱ�ȭ�� �����մϴ�. */
	void UnloadAnimation();

private:
	/** �÷��̾� ������ �� ������ �ؽ�ó ��Ʋ���Դϴ�. */
	TextureAtlas2D* textureAtlas_ = nullptr;

	/** ������ �����Դϴ� */
	Rect2D renderBound_;

	/** �÷��̾��� ������ �ɼ��Դϴ�. */
	TextureDrawOption renderOption_;

	/** �浹 �����Դϴ�. */
	Circle2D collisionBound_;

	/** �÷��̾��� �׸����Դϴ�. */
	Shadow shadow_;

	/** �÷��̾��� �̵� �����Դϴ�. */
	glm::vec2 direction_;
	
	/** �÷��̾��� �ӵ��Դϴ�. */
	float speed_ = 0.0f;
	
	/** ���� �ִϸ��̼��� �����Դϴ�. */
	EAnimationState animationState_ = EAnimationState::IDLE;

	/** �÷��̾��� �ִϸ��̼� ���� �� �ִϸ��̼� ���ҽ��Դϴ�. */
	std::map<EAnimationState, SpriteAnimator2D*> animations_;
};