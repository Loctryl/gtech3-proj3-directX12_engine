#include "Particle.h"
#include "Engine/Component/Transform.h"
#include "Engine/Component/PhysicsComponent.h"

Particle::Particle(float index, XMFLOAT3 velocity, float lifetime, XMFLOAT4 color, float angle, float size, XMFLOAT3 position)
{
	mIndex = index;

	mPhysics = new PhysicsComponent(mTransform, false, 1);
	AddComponent<PhysicsComponent>(mPhysics);

	mRender = new RenderComponent(SPHERE);
	mRender->SetColor(color);
	AddComponent<RenderComponent>(mRender);

	mTransform->SetPosition(position);

	float angleInRadians = angle * XM_PI / 180;
	velocity.x *= cos(angleInRadians);
	velocity.y *= -sin(angleInRadians);
	velocity.z *= tan(angleInRadians);

	mPhysics->SetVelocity(velocity);

	mOriginLifetime = lifetime;
	mLifetime = lifetime;
	mOriginSize = size;
	mSize = size;
	mColor = color;

	mTransform->SetScale(size);
}

Particle::~Particle()
{
	int a = 0;
}

void Particle::OnInit()
{
}

void Particle::OnUpdate(float deltaTime)
{
}

void Particle::OnDestroy()
{
}

void Particle::OnCollision(GameObject* gt)
{
}

float Particle::GetOriginLifeTime()
{
	return mOriginLifetime;
}

float Particle::GetIndex()
{
	return mIndex;
}

void Particle::SetOriginLifeTime(float value)
{
	mOriginLifetime = value;
}

void Particle::SetIndex(float index)
{
	mIndex = index;
}

float Particle::GetLifeTime()
{
	return mLifetime;
}

void Particle::SetLifeTime(float value)
{
	mLifetime = value;
}

float Particle::GetOriginSize()
{
	return mOriginSize;
}

void Particle::SetOriginSize(float value)
{
	mOriginSize = value;
}

float Particle::GetSize()
{
	return mSize;
}

void Particle::SetSize(float value)
{
	mSize = value;
}

XMFLOAT4 Particle::GetColor()
{
	return mColor;
}

void Particle::SetColor(XMFLOAT4 color)
{
	mColor = color;
}

PhysicsComponent* Particle::GetPhysics()
{
	return mPhysics;
}

