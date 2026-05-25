//
// Created by user on 2026/05/25.
//
#include <DxLib.h>
#include "Enemy.h"
#include "../Debug/ImGUI/imgui.h"

Enemy::Enemy(Location2D loc, Vector2D vec)
    : Base2DObject("Enemy", loc, vec, true){
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
    ImGui::SliderFloat("X:", &location_.x_, -1000.0f, 1000.0f);
    ImGui::SliderFloat("Y:", &location_.y_, -1000.0f, 1000.0f);
    ImGui::End();
}

void Enemy::Draw() {
    if (hModel_ == -1) return;
    MV1SetPosition(hModel_, {location_.x_, location_.y_, 10});
    MV1DrawModel(hModel_);
}

void Enemy::Release() {

}

