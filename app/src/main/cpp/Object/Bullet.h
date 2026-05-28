//
// Created by user on 2026/05/27.
//

#ifndef MYDXLIB_ANDROID_BULLET_H
#define MYDXLIB_ANDROID_BULLET_H


#include "Base3DObject.h"
#include "../Library/Location3D.h"
#include "../Library/Vector3D.h"

namespace {
    inline const float MAX_LIFE_TIME = 60.0f;
}

class Bullet : public Base3DObject {
private:
    int hModel_;
    float lifeTime_;
public:
    Bullet(Location3D loc, Vector3D vec);
    ~Bullet() override;
    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;

};


#endif //MYDXLIB_ANDROID_BULLET_H
