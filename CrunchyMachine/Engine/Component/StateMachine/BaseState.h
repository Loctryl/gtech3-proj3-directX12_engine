#pragma once
#include "Engine/GameObject.h"

class BaseState
{
public:

	BaseState();
	~BaseState() = default;

	virtual void OnStart() = 0;
	virtual void OnUpdate(float deltatime) = 0;
	virtual void OnEnd() = 0;

	inline void SetGameObject(GameObject* gameObject) {	mGameObject = gameObject ; }

protected:
	GameObject* mGameObject;
};