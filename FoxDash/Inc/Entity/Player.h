#pragma once

#include <map>
#include <list>

#include "Entity/IEntity2D.h"
#include "GL/RenderManager2D.h"
#include "Physic/Circle2D.h"
#include "Physic/Rect2D.h"

/** Ŭ���� ���� �����Դϴ�. */
class GamePlayScene;
class GamePlayRecorder;
class SpriteAnimator2D;
class TextureAtlas2D;
class Sound;
class Playground;
class UIBar;
class UISkill;

/** �÷��̾ ������ ��ƼƼ�Դϴ�. */
class Player : public IEntity2D
{
public:
	/** �÷��̾��� �����Դϴ�. */
	enum class EState
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

	/** �÷��̾��� �߽� ��ġ�� ����ϴ�. */
	const glm::vec2 GetPosition() const;

	/** �÷��̾��� ��� �浹 ������ ����ϴ�. */
	const Circle2D* GetCollider() const { return &collisionBound_; }

	/** �÷��̾��� HP�� ����ϴ�. */
	float GetHP() const;

	/** �÷��̾��� HP�� �����մϴ�. */
	void SetHP(float hp);

	/** �÷��̾��� �ִ� HP�� ����ϴ�. */
	float GetMaxHP() const;

	/** �÷��̾��� �ִ� HP�� �����մϴ�. */
	void SetMaxHP(float maxHp);

	/** �÷��̾��� MP�� ����ϴ�. */
	float GetMP() const;

	/** �÷��̾��� MP�� �����մϴ�. */
	void SetMP(float mp);

	/** �÷��̾��� �ִ� MP�� ����ϴ�. */
	float GetMaxMP() const;

	/** �÷��̾��� �ִ� MP�� �����մϴ�. */
	void SetMaxMP(float maxMP);

	/** �÷��̾��� ���� ���� ����ϴ�. */
	int32_t GetCoin() const { return coin_; }

	/** �÷��̾��� ���� ���� �ϳ� ������ŵ�ϴ�. */
	void AddCoin();

	/** �÷��̾��� ���¸� ����ϴ�. */
	const EState& GetState() const { return state_; }

private:
	/** �÷��̾��� ��ų �����Դϴ�. */
	enum class ESkill
	{
		NONE          = 0x00, // ��ų�� ������� �ʴ� �����Դϴ�. 
		DASH          = 0x01, // �÷��̾��� ���� ��ų�Դϴ�.
		INVINCIBILITY = 0x02, // �÷��̾��� ����(invincibility) ��ų�Դϴ�.
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
	void UnloadAnimations();

	/** �÷��̾��� UI ��Ҹ� �ʱ�ȭ�մϴ�. */
	void LoadUIs();

	/** �÷��̾��� UI ��Ҹ� �ʱ�ȭ �����մϴ�. */
	void UnloadUIs();

	/** �÷��̾��� ���� ��Ҹ� �ʱ�ȭ�մϴ�. */
	void LoadSounds();

	/** �÷��̾��� ���� ��Ҹ� �ʱ�ȭ �����մϴ�. */
	void UnloadSounds();

	/** �÷��̾��� �뽬 ��ų�� �����մϴ�. */
	void UseDashSkill(float deltaSeconds);

	/** �÷��̾��� ü�� ���� ����Ʈ�� �����մϴ�. */
	void LostHpEffect(float deltaSeconds);

	/** �÷��̾ �����Դϴ� */
	void Move(float deltaSeconds, float speed);
	
	/** �÷��̾��� ������/�浹/�׸��� ��ġ�� �����մϴ�. */
	void AdjustPosition(const glm::vec2& position);

	/** �÷��̾��� �ܻ��� �������մϴ�. */
	void RenderPlayerAfterImage(TextureAtlas2D* animationTexture, const std::string& animationClipName);

	/** �÷��̾ �������մϴ�. */
	void RenderPlayer(TextureAtlas2D* animationTexture, const std::string& animationClipName);

private:
	/** �÷��̾� ������ �� ������ �ؽ�ó ��Ʋ���Դϴ�. */
	TextureAtlas2D* textureAtlas_ = nullptr;

	/** ���� �÷��� ����� �����ϴ� ��ƼƼ�Դϴ�. */
	GamePlayRecorder* gamePlayRecorder_ = nullptr;

	/** �÷��� �׶����Դϴ�. */
	Playground* playground_ = nullptr;

	/** ���� �÷��� ���Դϴ�. */
	GamePlayScene* gamePlayScene_ = nullptr;

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
		
	/** ���� �÷��̾��� �����Դϴ�. */
	EState state_ = EState::IDLE;

	/** �÷��̾��� ���� �� �ִϸ��̼� ���ҽ��Դϴ�. */
	std::map<EState, SpriteAnimator2D*> animations_;

	/** �÷��̾��� ���� ���Դϴ�. */
	int32_t coin_ = 0;

	/** �÷��̾��� ü���� ��Ÿ���� HP�Դϴ�. */
	UIBar* hpBar_ = nullptr;

	/** �÷��̾��� ������ ��Ÿ���� MP�Դϴ�. */
	UIBar* mpBar_ = nullptr;

	/** �÷��̾��� ��ų�Դϴ�. */
	std::map<ESkill, UISkill*> skills_;

	/** �÷��̾��� ��ų�� ����� �� �Ҹ�Ǵ� ���� ���Դϴ�. */
	std::map<ESkill, float> skillMpCosts_;

	/** �÷��̾ ������ �� ǥ���� �����Դϴ�. */
	glm::vec4 invincibilityColor_;

	/** �÷��̾��� �뽬 �ӵ��Դϴ�. */
	float dashSpeed_ = 0.0f;
	
	/** �ִ� �뽬 �ӵ��Դϴ�. */
	float maxDashSpeed_ = 0.0f;

	/** �÷��̾��� �뽬 �Ÿ��Դϴ�. */
	float dashLength_ = 0.0f;

	/** �÷��̾��� ���� ������ ���� ��ġ�Դϴ�. */
	glm::vec2 prevPosition_ = glm::vec2(0.0f, 0.0f);

	/** �÷��̾��� ���� ������ ���� ��ġ�Դϴ�. */
	glm::vec2 currPosition_ = glm::vec2(0.0f, 0.0f);

	/** �÷��̾� �뽬�� �ܻ� ǥ���� ���� ������ ī��Ʈ ���Դϴ�. */
	static const uint32_t DASH_AFTER_IMAGE_COUNT = 10;

	/** �÷��̾ �뽬 ������ Ȯ���մϴ�. */
	bool bIsDashing_ = false;

	/** �÷��̾� ü���� �������� �� ǥ���� �����Դϴ�. */
	glm::vec4 lostHpColor_;

	/** �÷��̾ ü���� �����ߴ��� Ȯ���մϴ�. */
	bool bIsLostHp_ = false;

	/** �÷��̾��� ü���� �������� �� �����Ÿ��� ȿ���� �ִ� Ƚ���Դϴ�. */
	int32_t maxLostHpEffectCount_ = 0;

	/** �÷��̾��� ü�� ���� ȿ�� �ð��� �ִ밪�Դϴ�. */
	float maxLostHpEffectTime_ = 0.0f;

	/** �÷��̾��� ü���� �������� �� �����Ÿ��� ȿ���� Ƚ���Դϴ�. */
	int32_t lostHpEffectCount_ = 0;

	/** ���� ü�� ���� ȿ�� �ð� ���Դϴ�. */
	float lostHpEffectTime_ = 0.0f;

	/** HP/MP�� ȸ���Ǿ��� �� ����� �����Դϴ�. */
	Sound* chargeSound_ = nullptr;

	/** �÷��̾ �뽬 ��ų�� ������� �� ����� �����Դϴ�. */
	Sound* dashSound_ = nullptr;

	/** �÷��̾ hurt ���°� �Ǿ��� �� ����� �����Դϴ�. */
	Sound* hurtSound_ = nullptr;
};