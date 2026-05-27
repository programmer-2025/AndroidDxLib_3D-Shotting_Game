//
// Created by user on 2026/05/27.
//

#include <DxLib.h>
#include "Bullet.h"
#include "../MyDxlib.h"

Bullet::Bullet(Location3D loc, Vector3D vec)
    : Base3DObject("Bullet", loc, vec, true){
    hModel_ = -1;
    lifeTime_ = MAX_LIFE_TIME;
}

Bullet::~Bullet() {

}

void Bullet::Init() {
    hModel_ = MV1LoadModel("bullet.mv1");
}

void Bullet::Update() {
    location_.z_ += vector_.z_;
    lifeTime_ -= DELTA_TIME;
    if (lifeTime_ <= 0.0f) {
        isAlive_ = false;
    }
}

void Bullet::Draw() {
    if (!isAlive_) return;
    MV1SetPosition(hModel_, {location_.x_, location_.y_, location_.z_});
    MV1DrawModel(hModel_);
}

void Bullet::Release() {

}
