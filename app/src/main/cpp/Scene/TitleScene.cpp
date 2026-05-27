//
// Created by user on 2026/05/25.
//

#include "TitleScene.h"
#include <DxLib.h>
#include "../MyDxlib.h"
#include "../Manager/SceneManager.h"

using namespace DxLibParams;

void TitleScene::Init() {

}

void TitleScene::Update() {
    if (GetTouchInputNum() > 0) {
        SceneManager::ChangeScene("PlayScene");
    }
}

void TitleScene::Draw() {
    int fontSize = GetFontSize();
    DrawString(WIDTH / 2 - ((fontSize * 20) / 2), HEIGHT / 2, "ゲームを開始するにはタップしてください", GetColor(0, 0, 0));
}

void TitleScene::Release() {

}
