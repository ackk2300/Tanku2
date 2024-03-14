#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Ground.h"
#include "TankHead.h"
#include "Engine/Camera.h"

//カメラ制御
enum CAM_TYPE
{
	FIXED_TYPE, //固定
	TPS_NOROT_TYPE, //３人称回転なし
	TPS_TYPE,   //3人称
	FPS_TYPE,    //一人称
	MAX_TYPE    //番兵さん（チェック用の値）
};

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1),
	speed_(0.15),front_({0,0,1,0}),camState_(CAM_TYPE::FIXED_TYPE)
{
}

Tank::~Tank()
{
	//後片付け
}

void Tank::Initialize()
{
	hModel_ = Model::Load("tank.fbx");
	assert(hModel_ >= 0);
	Instantiate<TankHead>(this);
}

void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_W))
	{
		dir = 1.0;
	}
	if (Input::IsKey(DIK_S))
	{
		dir = -1.0;
	}
	if (Input::IsKey(DIK_A))
	{
		this->transform_ . rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D)) {
		this->transform_.rotate_.y += 1;
	}

	//回転行列を求める
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//ベクトルの回転結果を求める
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir * move; //実際に位置を動かす
	XMStoreFloat3(&(transform_.position_), pos);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData date;
	date.start = transform_.position_;
	date.start.y = 0;
	date.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &date);

	if ((date.hit == true))
	{
		transform_.position_.y = -date.dist;
	}

	if (Input::IsKeyDown(DIK_Z)) {
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3{ 0,20,-20 });
		Camera::SetTarget(XMFLOAT3{ 0,0,0 });
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 20.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR yEye{ 0,5,-10,0 };
		yEye = XMVector3TransformCoord(yEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + yEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		//XMFLOAT3 camTarget;
		//XMVECTOR vMove = XMFLOAT3(&(pos + dir * move));
		//XMStoreFloat3(&camTarget.pos + dir * move);
		//Camera::SetTarget(camTarget);
		break;
	}
	default:
		break;
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
