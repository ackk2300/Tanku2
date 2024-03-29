#include "Clear_Scene.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

Clear_Scene::Clear_Scene(GameObject* parent)
	: GameObject(parent, "Clear_Scene")
{
}

//初期化
void Clear_Scene::Initialize()
{
	Instantiate<TitleImage>(this);
}

//更新
void Clear_Scene::Update()
{
}

//描画
void Clear_Scene::Draw()
{
}

//開放
void Clear_Scene::Release()
{
}