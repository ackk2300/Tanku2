#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "TankHead.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "HUD.h"

namespace
{
	const int ENEMY_NUM{ 30 };
}

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),pText(nullptr)
{
}

PlayScene::~PlayScene()
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	//敵をインスタンス化
	enemyNum = ENEMY_NUM;
	for (int i = 0; i < enemyNum; i++)
	Instantiate<Enemy>(this);
	//enemyNum = ENEMY_NUM;

	pText = new Text;
	pText->Initialize();

	Instantiate<HUD>(this);
}

//更新
void PlayScene::Update()
{
	//タンクと一緒にカメラを動かすよ
	//Camera::SetTarget(player->GetPosition());
	//XMFLOAT3 camPos = player->GetPosition();
	//camPos.y += 8;
	//camPos.z -= 15;
	//Camera::SetPosition(camPos);
}

//描画
void PlayScene::Draw()
{
	pText->Draw(50, 55, "Teki");
}

//開放
void PlayScene::Release()
{
}