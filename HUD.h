#pragma once
#include "Engine/GameObject.h"
#include <vector>
#include <string>

using std::string;

class HUD :
    public GameObject
{
	string ConstructEnemyNumberString();
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	HUD(GameObject* parent);
	int hHUD_; //�c��@
	int hNumbers_; //�����̉摜
	int hKinoko_;
	Transform tHud_;
	std::vector<Transform>tNumbers;

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

