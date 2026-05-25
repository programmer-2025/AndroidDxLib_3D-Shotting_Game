//
// Created by user on 2026/05/25.
//

#ifndef MYDXLIB_ANDROID_CLEARSCENE_H
#define MYDXLIB_ANDROID_CLEARSCENE_H

#include "BaseScene.h"

class ClearScene : public BaseScene{
private:
public:
    ClearScene()
            : BaseScene("ClearScene"){
    }

    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};



#endif //MYDXLIB_ANDROID_CLEARSCENE_H
