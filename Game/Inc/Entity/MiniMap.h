#pragma once

#include "Entity/IEntity2D.h"
#include "GL/RenderManager2D.h"
#include "Physic/Rect2D.h"

/** Ŭ���� ���� �����Դϴ�. */
class UICamera;
class RandomChest;
class Player;
class Playground;
class TextureAtlas2D;

/** ��ü ���� ���带 ����ؼ� �����ִ� �̴ϸ� ��ƼƼ�Դϴ�. */
class MiniMap : public IEntity2D
{
public:
	MiniMap(UICamera* uiCamera);
	virtual ~MiniMap();

	DISALLOW_COPY_AND_ASSIGN(MiniMap);

	virtual void Tick(float deltaSeconds) override;
	virtual void Render() override;
	virtual void Release() override;
	
private:
	/** �̴ϸ� �������� ������ �� UI ī�޶��Դϴ�. */
	UICamera* uiCamera_ = nullptr;

	/** �̴ϸ� ������ �� ������ �ؽ�ó ��Ʋ���Դϴ�. */
	TextureAtlas2D* textureAtlas_ = nullptr;

	/** ������ �����Դϴ�. */
	Rect2D renderBound_;

	/** �÷��̾��Դϴ�. */
	Player* player_ = nullptr;

	/** �÷��� ������ ������ �����Դϴ�. */
	float playgroundRadius_ = 0.0f;

	/** �̴ϸ� ������ �����Դϴ�. */
	float minimapRadius_ = 0.0f;

	/** �̴ϸʿ� ǥ���� ���� ũ���Դϴ�. */
	float pointSize_ = 0.0f;

	/** �̴ϸ� ���� �÷��̾� ��ġ�Դϴ�. */
	glm::vec2 playerPosition_ = glm::vec2(0.0f, 0.0f);

	/** �̴ϸ� ���� �÷��̾��� �����Դϴ�. */
	glm::vec4 playerColor_ = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
};