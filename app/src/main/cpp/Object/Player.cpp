//
// Created by user on 2026/05/27.
//

#include <DxLib.h>
#include "Player.h"
#include "Bullet.h"
#include "../Debug/ImGUI/imgui.h"

Player::Player(Location3D loc, Vector3D vec)
        : Base3DObject("Player", loc, vec, true){
    hModel_ = -1;
}

Player::~Player() {

}

void Player::Init() {
    hModel_ = MV1LoadModel("player.mv1");
}

void Player::Update() {
    static int beforeTouch = 0;
    int afterTouch = GetTouchInputNum();
    if (beforeTouch == 0 && GetTouchInputNum() > 0) {
        auto bullet = new Bullet(location_, Vector3D{0, 0, 20});
        bullet->Init();
    }
    beforeTouch = afterTouch;
}

void Player::Draw() {
    MV1SetPosition(hModel_, {location_.x_, location_.y_, location_.z_});
    MV1DrawModel(hModel_);

    ImGui::Begin("Player");
    ImGui::SliderFloat("X:", &location_.x_, -1000.0f, 5000.0f);
    ImGui::SliderFloat("Y:", &location_.y_, -1000.0f, 5000.0f);
    ImGui::SliderFloat("Z:", &location_.z_, -1000.0f, 5000.0f);
    ImGui::End();
}

void Player::Release() {

}