#pragma once
#include "Engine/GameObject.h"

class UIElement;

class Score : public GameObject
{
	void virtual OnInit() override;
	void virtual OnUpdate(float deltaTime) override;
	void virtual OnDestroy() override;
	void virtual OnCollision(GameObject* gt) override;

public:
	Score();

	int mScore;
	vector<UIElement*> mDigits;

	void SetDigits(int num);
};

