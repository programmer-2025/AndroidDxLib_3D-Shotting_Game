//
// Created by user on 2026/05/25.
//

#ifndef MYDXLIB_ANDROID_TITLESCENE_H
#define MYDXLIB_ANDROID_TITLESCENE_H
#include "BaseScene.h"

class TitleScene : public BaseScene{
private:
public:
    TitleScene()
            : BaseScene("TitleScene"){
    }

    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};


#endif //MYDXLIB_ANDROID_TITLESCENE_H
