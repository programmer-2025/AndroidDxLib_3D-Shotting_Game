//
// Created by user on 2026/05/27.
//

#ifndef MYDXLIB_ANDROID_PLAYER_H
#define MYDXLIB_ANDROID_PLAYER_H

#include "Base3DObject.h"
#include "../Library/Location3D.h"
#include "../Library/Vector3D.h"

class Player : public Base3DObject {
private:
    int hModel_;
public:
    Player(Location3D loc, Vector3D vec);
    ~Player() override;
    void Update() override;
    void Draw() override;
    void Init() override;
    void Release() override;
};


#endif //MYDXLIB_ANDROID_PLAYER_H
