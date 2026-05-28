//
// Created by user on 2026/05/25.
//

#include <DxLib.h>
#include "ClearScene.h"
#include "../MyDxLib.h"
#include "../Manager/SceneManager.h"

using namespace DxLibParams;

void ClearScene::Init() {

}

void ClearScene::Update() {
    if (GetTouchInputNum() > 0) {
        SceneManager::ChangeScene("TitleScene");
    }
}

void ClearScene::Draw() {
    int fontSize = GetFontSize();
    DrawString(WIDTH / 2 - ((fontSize * 20) / 2), HEIGHT / 2, "ゲーム終了! タップで戻ります", GetColor(0, 0, 0));
}

void ClearScene::Release() {

}
