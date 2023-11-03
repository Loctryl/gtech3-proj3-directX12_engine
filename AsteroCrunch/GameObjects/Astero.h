#pragma once
#include "Engine/GameObject.h"

class Input;

class Astero : public GameObject
{
	void virtual OnInit() override;
	void virtual OnUpdate(float deltaTime) override;
	void virtual OnDestroy() override;

public:

	Astero();

private:
	Input* mInput;
};
