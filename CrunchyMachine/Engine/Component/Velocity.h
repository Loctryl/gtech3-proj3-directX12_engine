#pragma once
#include "Resources/framework.h"
#include "Engine/Component/Component.h"

class Velocity : public Component {

public:
	Velocity();
	Velocity(XMFLOAT3* position);
	~Velocity() = default;

	void SetVelocity(XMFLOAT3 velocity);
	void SetVelocity(float x, float y, float z);

	XMFLOAT3 inline GetVelocity() { return mVelocity; };

private:
	//Tranform* transform;
	XMFLOAT3 mVelocity = { 0.0F , 0.0F, 0.0F };
};