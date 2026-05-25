//
// Created by user on 2026/03/12.
//

#pragma once
#ifndef MYDXLIB_ANDROID_OBJECTMANAGER_H
#define MYDXLIB_ANDROID_OBJECTMANAGER_H

#include "../Object/BaseObject.h"
#include <vector>

namespace ObjectManager {

    void InitManager();
    void AddObject(BaseObject* object);
    void RemoveObject(BaseObject* object);
    std::vector<BaseObject*>& GetAllObjects();
    void ClearObjects();

    void UpdateAllObjects();
    void DrawAllObjects();

     template<class C> C* GetDrawObject() {
        for (BaseObject* obj : GetAllObjects()) {
            if (obj == nullptr) continue;
            C* instance = dynamic_cast<C*>(obj);
            if (instance != nullptr) {
                return instance;
            }
        }
        return nullptr;
    }
}


#endif //MYDXLIB_ANDROID_OBJECTMANAGER_H