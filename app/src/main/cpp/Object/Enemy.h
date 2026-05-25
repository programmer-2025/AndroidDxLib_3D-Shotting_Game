//
// Created by user on 2026/05/25.
//

#ifndef MYDXLIB_ANDROID_ENEMY_H
#define MYDXLIB_ANDROID_ENEMY_H

#include "Base3DObject.h"

class Enemy : public Base3DObject {
private:
    int hModel_;
public:
    Enemy(Location3D loc, Vector3D vec);
    ~Enemy() override;
    void Update() override;
    void Draw() override;
    void Init() override;
    void Release() override;

};

#endif //MYDXLIB_ANDROID_ENEMY_H
