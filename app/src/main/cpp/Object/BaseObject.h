//
// Created by user on 2026/03/12.
//

#ifndef MYDXLIB_ANDROID_BASEOBJECT_H
#define MYDXLIB_ANDROID_BASEOBJECT_H

#pragma once
#include <string>

class BaseObject {
private:
protected:
    std::string name_;
    bool isAlive_;
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Release() = 0;

    BaseObject(const std::string& name, const bool isAlive);
    virtual ~BaseObject() = default;

    std::string GetName() const { return name_; };
    bool IsAlive() const { return isAlive_; };
};

#endif //MYDXLIB_ANDROID_BASEOBJECT_H