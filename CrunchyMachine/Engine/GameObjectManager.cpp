#include "GameObjectManager.h"
#include "GameObject.h"

GameObjectManager* GameObjectManager::mInstance = nullptr;

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	mGameObjects.clear();
	mGameObjectsToInit.clear();
}

GameObjectManager* GameObjectManager::GetInstance()
{
	if (mInstance != nullptr) return mInstance;
	mInstance = new GameObjectManager();
	mInstance->Init();
	return mInstance;
}

void GameObjectManager::Init()
{
}

void GameObjectManager::Run(GameTimer* gt)
{
	// Initialize the news games objects

	std::vector<int> toUpdateIndex = std::vector<int>();
	int maxindex = mGameObjectsToInit.size();

	for (int i = 0; i < maxindex; i++) {
		mGameObjectsToInit[i]->OnInit(gt);
		toUpdateIndex.push_back(i);
		mGameObjects.push_back(mGameObjectsToInit[i]);
	}
	for (int i = 0; i < toUpdateIndex.size(); i++) {
		mGameObjectsToInit.erase(mGameObjectsToInit.begin() + toUpdateIndex[i] - i);
	}


	for (int i = 0; i < mGameObjects.size(); i++)
		if (!mGameObjects[i]->ToDestroy)
			mGameObjects[i]->OnUpdate(gt);

}

void GameObjectManager::DeleteGameObject(GameTimer* gt)
{
	std::vector<int> toRemove = std::vector<int>();

	for (int i = 0; i < mGameObjects.size(); i++) {
		if (mGameObjects[i]->ToDestroy) {
			mGameObjects[i]->OnDestroy(gt);
			mGameObjects[i]->~GameObject();
			toRemove.push_back(i);
		}
	}

	
	for (int i = 0; i < toRemove.size(); i++) {
		mGameObjects.erase(mGameObjects.begin() + toRemove[i]-i);
	}
}

void GameObjectManager::AddGameObject(GameObject* go)
{
	mGameObjectsToInit.push_back(go);
}
