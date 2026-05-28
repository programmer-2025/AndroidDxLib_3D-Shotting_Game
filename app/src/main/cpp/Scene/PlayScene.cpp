//
// Created by user on 2026/05/25.
//

#include <DxLib.h>
#include "PlayScene.h"
#include "../Object/Enemy.h"
#include "../Object/Player.h"

namespace {
    Player* player = nullptr;
}

void PlayScene::Init() {
    ChangeLightTypeDir(VECTOR{0, 1, 0});
    new Enemy(Location3D{0, 0, 0}, Vector3D{0, 0, 0});
    player = new Player(Location3D{0, 0, 0}, Vector3D{0, 0, 0});
}

void PlayScene::Update() {

}

void PlayScene::Draw() {

}

void PlayScene::Release() {

}
