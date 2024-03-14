#include "Clear_Scene.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

Clear_Scene::Clear_Scene(GameObject* parent)
	: GameObject(parent, "Clear_Scene")
{
}

//‰Šú‰»
void Clear_Scene::Initialize()
{
	Instantiate<TitleImage>(this);
}

//XV
void Clear_Scene::Update()
{
}

//•`‰æ
void Clear_Scene::Draw()
{
}

//ŠJ•ú
void Clear_Scene::Release()
{
}