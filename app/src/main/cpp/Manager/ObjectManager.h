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
            if (!obj->IsAlive()) continue;
            C* instance = dynamic_cast<C*>(obj);
            if (instance != nullptr) {
                return instance;
            }
        }
        return nullptr;
    }

    template<class C> std::vector<C*> GetDrawObjectList() {
        std::vector<C*> result;
        for (BaseObject* obj : GetAllObjects()) {
            if (obj == nullptr) continue;
            if (!obj->IsAlive()) continue;
            C* instance = dynamic_cast<C*>(obj);
            if (instance != nullptr) {
                result.push_back(instance);
            }
        }
        return result;
    }
}


#endif //MYDXLIB_ANDROID_OBJECTMANAGER_H