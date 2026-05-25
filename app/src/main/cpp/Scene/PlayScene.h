//
// Created by user on 2026/05/25.
//

#ifndef MYDXLIB_ANDROID_PLAYSCENE_H
#define MYDXLIB_ANDROID_PLAYSCENE_H

#include "BaseScene.h"

class PlayScene : public BaseScene{
private:
public:
    PlayScene()
            : BaseScene("PlayScene"){
    }

    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};



#endif //MYDXLIB_ANDROID_PLAYSCENE_H
