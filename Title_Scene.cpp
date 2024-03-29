#include "Title_Scene.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

Title_Scene::Title_Scene(GameObject* parent)
	: GameObject(parent, "Title_Scene")
{
}

//初期化
void Title_Scene::Initialize()
{
	Instantiate<TitleImage>(this);
}

//更新
void Title_Scene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void Title_Scene::Draw()
{
}

//開放
void Title_Scene::Release()
{
}