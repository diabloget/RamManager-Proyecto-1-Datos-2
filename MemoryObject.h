//
// Created by diabloget on 5/9/21.
//

#ifndef RAMMANAGER_MEMORYOBJECT_H
#define RAMMANAGER_MEMORYOBJECT_H
#include "iostream"


class MemoryObject {
public:
    std::string type;
    std::string name;
    int scope;
    int memDirect;

    MemoryObject(std::string type, std::string name, int scope, int memDirect);
};


#endif //RAMMANAGER_MEMORYOBJECT_H
