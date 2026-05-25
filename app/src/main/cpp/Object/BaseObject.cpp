//
// Created by user on 2026/05/25.
//
#include "BaseObject.h"
#include "../Manager/ObjectManager.h"

BaseObject::BaseObject(const std::string &name, const bool isAlive) {
    name_ = name;
    isAlive_ = isAlive;
    ObjectManager::AddObject(this);
}