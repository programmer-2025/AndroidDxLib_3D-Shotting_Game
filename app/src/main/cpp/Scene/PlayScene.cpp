//
// Created by user on 2026/05/25.
//

#include "PlayScene.h"
#include "../Object/Enemy.h"

namespace {
}

void PlayScene::Init() {
    new Enemy(Location3D{0, 0, 0}, Vector3D{0, 0, 0});
}

void PlayScene::Update() {

}

void PlayScene::Draw() {

}

void PlayScene::Release() {

}
