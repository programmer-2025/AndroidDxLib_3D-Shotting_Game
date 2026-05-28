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
    static int result = 0;
    hModel_ = MV1LoadModel("bullet.mv1");
    result = MV1SetupCollInfo( hModel_, 0, 8, 8, 8 ) ;
}

void Bullet::Update() {
    location_.z_ += vector_.z_;
    MV1SetPosition(hModel_, {location_.x_, location_.y_, location_.z_});
    lifeTime_ -= DELTA_TIME;
    if (lifeTime_ <= 0.0f) {
        DeadMe();
    }
}

void Bullet::Draw() {
    MV1SetPosition(hModel_, {location_.x_, location_.y_, location_.z_});
    MV1DrawModel(hModel_);
}

void Bullet::Release() {

}
