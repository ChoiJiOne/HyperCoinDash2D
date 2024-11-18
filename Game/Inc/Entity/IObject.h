#pragma once

#include "IEntity2D.h"

/** 플레이어가 획득하거나 피해야 할 오브젝트의 인터페이스입니다. */
class IObject : public IEntity2D
{
public:
	/** 플레이어가 획득하거나 피해야 할 오브젝트의 타입입니다. */
	enum class EType
	{
		NONE = 0x00,
		COIN = 0x01, // 플레이어가 획득 가능한 코인입니다.
		FIRE = 0x02, // 플레이어가 피해야 할 불입니다.
	};

	/** 오브젝트의 현재 상태입니다. */
	enum class EState
	{
		NONE = 0x00, // 아무것도 아닌 상태.
		MOVE = 0x01, // 특정 위치로 이동 중.
		WAIT = 0x02, // 대기 중.
		DONE = 0x03, // 더 이상 업데이트를 수행할 수 없는 상태.
	};

public:
	IObject(const EType& type) : type_(type) {}
	virtual ~IObject() {}

	DISALLOW_COPY_AND_ASSIGN(IObject);

	virtual void Tick(float deltaSeconds) = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	/** 오브젝트의 타입을 얻습니다. */
	const EType& GetType() const { return type_; }

	/** 오브젝트의 상태를 얻습니다. */
	const EState& GetState() const { return state_; }

protected:
	/** 오브젝트의 타입입니다. */
	EType type_ = EType::NONE;

	/** 오브젝트의 상태입니다. */
	EState state_ = EState::NONE;
};