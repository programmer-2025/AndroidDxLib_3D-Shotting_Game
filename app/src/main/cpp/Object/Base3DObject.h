//
// Created by user on 2026/05/26.
//

#ifndef MYDXLIB_ANDROID_BASE3DOBJECT_H
#define MYDXLIB_ANDROID_BASE3DOBJECT_H

#include "BaseObject.h"
#include "../Library/Location3D.h"
#include "../Library/Vector3D.h"

class Base3DObject : public BaseObject {
protected:
    Location3D location_;
    Vector3D vector_;
public:
    Base3DObject(const std::string& name, const Location3D& location, const Vector3D& vector, const bool& isAlive)
            : BaseObject(name, isAlive){
        location_ = location;
        vector_ = vector;
    };
    ~Base3DObject() override = default;

    Location3D GetLocation() { return location_; };
    void SetLocation(const Location3D& loc) { location_ = loc; };
    Vector3D GetVector() { return vector_;  };
    void SetVector(const Vector3D& vec) { vector_ = vec; };
};

#endif //MYDXLIB_ANDROID_BASE3DOBJECT_H
