#include "TankHead.h"
#include "Engine//Model.h"
#include "Engine//Input.h"
#include "Bullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0); //エラーが返ってくる
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		this->transform_.rotate_.y -= 4.0;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		this->transform_.rotate_.y += 4.0;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		XMFLOAT3 CannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 CannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");
		XMVECTOR vtop = XMLoadFloat3(&CannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&CannonRootPos);

		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);

		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(CannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpped(0.2);
	}
}

void TankHead::Draw()
{
	//transform_は自分（TankHead）のメンバ関数
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void TankHead::Release()
{

}
