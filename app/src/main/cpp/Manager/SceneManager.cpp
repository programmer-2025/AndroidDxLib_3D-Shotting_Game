//
// Created by user on 2026/03/12.
//

#include <vector>
#include "SceneManager.h"
#include "../Scene/BaseScene.h"
#include "../Scene/BootScene.h"

namespace {
    std::vector<BaseScene*> sceneVector_;
    BaseScene* currentScene_;
}

namespace SceneManager {

    void InitManager() {
        sceneVector_.clear();

        sceneVector_.push_back(new BootScene());

        ChangeScene("BootScene");
    }

    void ChangeScene(const std::string& sceneName) {
        for (auto& scene : sceneVector_) {
            if (scene->GetName() == sceneName) {
                currentScene_ = scene;
                currentScene_->Init();
                break;
            }
        }
    }

    void UpdateCurrentScene() {
        if (currentScene_ == nullptr) return;
        currentScene_->Update();
    }

    void DrawCurrentScene() {
        if (currentScene_ == nullptr) return;
        currentScene_->Draw();
    }

    void InitCurrentScene() {
        if (currentScene_ == nullptr) return;
        currentScene_->Init();
    }

    void ReleaseCurrentScene() {
        if (currentScene_ == nullptr) return;
        currentScene_->Release();
    }
}