#pragma once

#include <string>

#include "Entity/IEntity2D.h"
#include "GL/RenderManager2D.h"
#include "Physic/Rect2D.h"

/** Ŭ������ ���� �����Դϴ�. */
class TTFont;
class UICamera;

/** UI �� ��ƼƼ�Դϴ�. */
class UIBar : public IEntity2D
{
public:
	/** UI ���� ���� �Ӽ��� �����ϱ� ���ؼ��� Json ������ ������ �ʿ��մϴ�. */
	UIBar(UICamera* uiCamera, TTFont* font, const std::string& barPath);
	virtual ~UIBar();

	DISALLOW_COPY_AND_ASSIGN(UIBar);

	virtual void Tick(float deltaSeconds) override;
	virtual void Render() override;
	virtual void Release() override;

	/** UI���� ���� Bar�� ����ϴ�. */
	float GetBar() const { return bar_; }

	/** UI���� Bar ���� �����մϴ�. */
	void SetBar(float bar);

	/** UI�� Bar�� �ִ� ���� ����ϴ�. */
	float GetMaxBar() const { return maxBar_; }
	
	/** UI�� Bar�� �ִ� ���� �����մϴ�. */
	void SetMaxBar(float maxBar);

private:
	/** UI�� ���� �Ӽ����� �ʱ�ȭ�մϴ�. */
	void InitProperties(const std::string& barPath);

private:
	/** UI�� �������� ������ �� UI ī�޶��Դϴ�. */
	UICamera* uiCamera_ = nullptr;

	/** UI�ٿ� �ؽ�Ʈ�� �������� �� ������ ��Ʈ�Դϴ�. */
	TTFont* font_ = nullptr;

	/** UI���� ��׶��� ũ���Դϴ�. */
	Rect2D background_;

	/** UI���� �����Դϴ�. */
	Rect2D barBound_;

	/** UI���� ��׶��� �����Դϴ�. */
	glm::vec4 backgroundColor_;

	/** UI���� �����Դϴ�. */
	glm::vec4 barColor_;

	/** UI�� ���� Bar�Դϴ�. */
	float bar_ = 0.0f;

	/** �ε巯�� ��ȯ�� ���� ��ũ�Դϴ�. */
	float barMark_ = 0.0f;

	/** UI�� ���� Bar �ִ� ���Դϴ�.. */
	float maxBar_ = 0.0f;

	/** �ε巯�� ��ȯ�� ���� �ӵ��Դϴ�. */
	float barSlideSpeed_ = 0.0f;

	/** UI�ٿ� ǥ���� �ؽ�Ʈ�Դϴ�. */
	std::wstring text_;
};