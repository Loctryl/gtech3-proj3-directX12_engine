#pragma once
#include "Resources/framework.h"
#include "Window/Window.h"
#include "DirectX12/D3DApp.h"
#include "GameTimer.h"
#include "Input.h"

class Application
{
	Window mMainWindow;
	D3DApp mDirectX;
	GameTimer mTimer;
	Input mInput;

	bool mAppPaused;

	void CalculateFrameStats();

	void Update(GameTimer timer);

	void Render(GameTimer timer);

public:
	Application();
	~Application() = default;

	void Init();

	int Run();
};

