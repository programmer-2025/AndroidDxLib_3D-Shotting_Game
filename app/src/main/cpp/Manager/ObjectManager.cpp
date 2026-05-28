//
// Created by user on 2026/03/12.
//

#include "ObjectManager.h"


namespace {
    std::vector<BaseObject*> allObjects;
}

namespace ObjectManager {

    void InitManager() {
        for (BaseObject* baseObject : allObjects) {
            baseObject->Init();
        }
    }

    void AddObject(BaseObject* object){
        allObjects.push_back(object);
    }

    void RemoveObject(BaseObject* object){
        std::vector<BaseObject*>& all = GetAllObjects();
        for (auto it = all.begin(); it != all.end(); ) {
            if ((*it) == object) {
                delete *it;
                it = all.erase(it);
            }
            else {
                it++;
            }
        }
    }

    std::vector<BaseObject*>& GetAllObjects() {
        return allObjects;
    }

    void ClearObjects() {
        allObjects.clear();
    }

    void UpdateAllObjects() {
        for (int i = 0; i < allObjects.size(); i++) {
            auto obj = allObjects[i];
            if (obj == nullptr) continue;
            if (!obj->IsAlive()) {
                RemoveObject(obj);
            }
            else {
                obj->Update();
            }
        }
    }

    void DrawAllObjects() {
        for (int i = 0; i < allObjects.size(); i++) {
            auto obj = allObjects[i];
            if (obj == nullptr) continue;
            obj->Draw();
        }
    }

}