#pragma once
#include "Engine/GameObject.h"

class Input;
class PhysicsComponent;
class DefaultState;
class SpaceShipPart;

class Astero : public GameObject
{
	void virtual OnInit() override;
	void virtual OnUpdate(float deltaTime) override;
	void virtual OnDestroy() override;
	void virtual OnCollision(GameObject* gt) override;

public:

	Astero();

private:
	SpaceShipPart* mPartTest;
	DefaultState* state;
	PhysicsComponent* physics;
};

