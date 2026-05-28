//
// Created by user on 2026/05/25.
//
#include <DxLib.h>
#include "Enemy.h"
#include "../Debug/ImGUI/imgui.h"
#include "../Manager/ObjectManager.h"
#include "Bullet.h"

namespace {
    MATRIX matrix = {};
}

Enemy::Enemy(Location3D loc, Vector3D vec)
    : Base3DObject("Enemy", loc, vec, true){
    hModel_ = -1;
    time_ = 0;
}

Enemy::~Enemy() = default;

void Enemy::Init() {
    static int result = 0;
    hModel_ = MV1LoadModel("enemy.mv1");
    location_.z_ = 5000;
    result = MV1SetupCollInfo( hModel_, 0, 8, 8, 8 ) ;
}

void Enemy::Update() {
    if (hModel_ == -1) return;
    double sinX = sin(time_) * 1000;
    double cosY = cos(time_) * 1000;
    //location_.x_ = ((float) sinX)+400;

    MATRIX translate = MGetTranslate(VECTOR{location_.x_, location_.y_, location_.z_});
    MATRIX scale = MGetScale(VECTOR{4.0, 4.0, 4.0});
    MATRIX matrix = MMult(scale, translate);
    MV1SetMatrix(hModel_, matrix);

    time_+=0.05;

    auto bullets = ObjectManager::GetDrawObjectList<Bullet>();
    for (Bullet* bullet : bullets) {
        float distance = location_.Distance(bullet->GetLocation());
        if (distance < 100) {
            isAlive_ = false;
        }
    }

    //デバック用
    ImGui::Begin("Enemy");
    ImGui::SliderFloat("X:", &location_.x_, -1000.0f, 5000.0f);
    ImGui::SliderFloat("Y:", &location_.y_, -1000.0f, 5000.0f);
    ImGui::SliderFloat("Z:", &location_.z_, -1000.0f, 5000.0f);
    ImGui::End();
}

void Enemy::Draw() {
    if (!isAlive_) return;
    if (hModel_ == -1) return;
    MV1SetPosition(hModel_, {location_.x_, location_.y_, location_.z_});
    MV1DrawModel(hModel_);
}

void Enemy::Release() {

}

