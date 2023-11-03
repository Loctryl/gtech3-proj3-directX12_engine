#pragma once
#include <vector>
#include "Engine/GameObject.h"

class Window;
class D3DApp;
class GameTimer;
class Camera;
class Input;
class GameObjects;

class Application
{
	Window* mMainWindow;
	D3DApp* mDirectX;
	GameTimer* mTimer;
	Input* mInput;

	std::vector<GameObject*> asts;

	bool mAppPaused;

	void CalculateFrameStats();

	void Update(GameTimer* timer);

	void Render();

	void EndFrame(float timer);

public:
	Application();
	~Application();

	void Init();

	int Run();
};
