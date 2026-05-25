//
// Created by user on 2026/05/25.
//
#include <DxLib.h>
#include "Enemy.h"
#include "../Debug/ImGUI/imgui.h"

Enemy::Enemy(Location3D loc, Vector3D vec)
    : Base3DObject("Enemy", loc, vec, true){
    hModel_ = -1;
}

Enemy::~Enemy() = default;

void Enemy::Init() {
    hModel_ = MV1LoadModel("enemy.mv1");
}

void Enemy::Update() {
    if (hModel_ == -1) return;

    //デバック用
    ImGui::Begin("Enemy");
    ImGui::SliderFloat("X:", &location_.x_, -1000.0f, 5000.0f);
    ImGui::SliderFloat("Y:", &location_.y_, -1000.0f, 5000.0f);
    ImGui::SliderFloat("Z:", &location_.z_, -1000.0f, 5000.0f);
    ImGui::End();
}

void Enemy::Draw() {
    if (hModel_ == -1) return;
    MV1SetPosition(hModel_, {location_.x_, location_.y_, location_.z_});
    MV1DrawModel(hModel_);
}

void Enemy::Release() {

}

