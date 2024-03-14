#include "Clear_Scene.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

Clear_Scene::Clear_Scene(GameObject* parent)
	: GameObject(parent, "Clear_Scene")
{
}

//������
void Clear_Scene::Initialize()
{
	Instantiate<TitleImage>(this);
}

//�X�V
void Clear_Scene::Update()
{
}

//�`��
void Clear_Scene::Draw()
{
}

//�J��
void Clear_Scene::Release()
{
}