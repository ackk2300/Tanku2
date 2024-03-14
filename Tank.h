#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
    int hModel_; //���f���ԍ�
    XMVECTOR front_; 
    float speed_;
    int camState_; // �J�����^�C�v�̎w��
public:
    //�R���X�g���N�^
    Tank(GameObject* parent);

    //�f�X�g���N�^
    ~Tank();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    int GetModelHandle() { return(hModel_); }
};