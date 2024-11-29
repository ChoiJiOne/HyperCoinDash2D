#pragma once

#include <list>

#include "Scene/IGameScene.h"
#include "GL/RenderManager2D.h"

/** Ŭ���� ���� �����Դϴ�. */
class PlayRecordViewer;
class UICamera;

/** ���� ����� �����ִ� ���Դϴ�. */
class GameRecordScene : public IGameScene
{
public:
	GameRecordScene();
	virtual ~GameRecordScene();

	DISALLOW_COPY_AND_ASSIGN(GameRecordScene);

	virtual void Tick(float deltaSeconds) override;
	virtual void Render() override;
	virtual void Enter() override;
	virtual void Exit() override;

private:
	/** ���� ��� ���� �ʱ�ȭ�մϴ�. */
	void Initailize();

	/** ���� ��� ���� �ʱ�ȭ�� �����մϴ�. */
	void UnInitailize();

private:	
	/** ���� ��� ���� ��ũ�� ī�޶��Դϴ�. */
	UICamera* uiCamera_ = nullptr;

	/** ������Ʈ�� UI ��ƼƼ�Դϴ�. */
	std::list<IEntity*> updateUiEntities_;

	/** �������� UI ��ƼƼ�Դϴ�. */
	std::list<IEntity2D*> renderUiEntities_;

	/** ���� �÷��� ����� �����ִ� ��ƼƼ�Դϴ�. */
	PlayRecordViewer* playRecordViewer_ = nullptr;
};