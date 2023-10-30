#pragma once
#include "Astero.h"

class Window;
class D3DApp;
class GameTimer;
class Camera;

class Application
{
	Window* mMainWindow;
	D3DApp* mDirectX;
	GameTimer* mTimer;

	vector<GameObject*> asts;

	bool mAppPaused;

	void CalculateFrameStats();

	void Update(GameTimer* timer);

	void Render(GameTimer* timer);

	void EndFrame(GameTimer* timer);

public:
	Application();
	~Application();

	void Init();

	int Run();
};

